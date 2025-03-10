package website

import (
	postgresql "Day06/source/database/postgreSQL"
	"html/template"
	"math"
	"net/http"
	"strconv"
	"time"

	ratelimit "github.com/JGLTechnologies/gin-rate-limit"
	"github.com/gin-gonic/gin"
	"github.com/russross/blackfriday/v2"
)

type server struct {
	port          string
	adminPassword string
	r             *gin.Engine
}

func NewServer(port, adminPassword string) server {
	return server{
		port:          port,
		adminPassword: adminPassword,
		r:             gin.Default(),
	}
}

func keyFunc(c *gin.Context) string {
	return c.ClientIP()
}

func errorHandler(c *gin.Context, info ratelimit.Info) {
	c.String(429, "Too many requests. Try again in "+time.Until(info.ResetTime).String())
}

func (s server) Run() {
	// Инициализируем DB
	postgresql.InitDB()

	// MW для ограничения пользователей
	store := ratelimit.InMemoryStore(&ratelimit.InMemoryOptions{
		Rate:  time.Second,
		Limit: 100,
	})
	mw := ratelimit.RateLimiter(store, &ratelimit.Options{
		ErrorHandler: errorHandler,
		KeyFunc:      keyFunc,
	})
	withLimiter := s.r.Group("/")
	withLimiter.Use(mw)

	// Кастомные функции для пагинации + подгрузка HTML
	s.r.SetHTMLTemplate(template.Must(template.New("").Funcs(template.FuncMap{
		"sub": func(a, b int) int {
			return a - b
		},
		"add": func(a, b int) int {
			return a + b
		},
	}).ParseGlob("templates/*")))

	// Нужно, чтобы Gin знал откуда брать статичные файлы
	// В нашем случае это пнг-картинку
	s.r.Static("../static", "./static")

	// Подгружаем ручки
	withLimiter.GET("/", mw, mainHandler)
	withLimiter.GET("/admin", adminGETHandler)
	withLimiter.POST("/admin", adminPOSTHandler)
	withLimiter.GET("/admin/login", loginAdminGETHandler)
	withLimiter.POST("/admin/login", loginAdminMiddleWare(s.adminPassword))
	withLimiter.GET("/article/:id", articleHandler)

	// Запускаем сервер
	s.r.Run("localhost:" + s.port)
}

func mainHandler(c *gin.Context) {
	page, err := strconv.Atoi(c.DefaultQuery("page", "1"))
	if err != nil || page < 1 {
		page = 1
	}

	offset := (page - 1) * 3

	var totalArticles int64
	postgresql.PostgreDB.Model(&postgresql.Article{}).Count(&totalArticles)
	totalPages := int(math.Ceil(float64(totalArticles) / float64(3)))

	var articles []postgresql.Article
	postgresql.PostgreDB.Order("created_at DESC").Offset(offset).Limit(3).Find(&articles)

	c.HTML(http.StatusOK, "main.html", gin.H{
		"articles":    articles,
		"page":        page,
		"total_pages": totalPages,
	})
}

func adminGETHandler(c *gin.Context) {
	if authCoolie, err := c.Cookie("adminAuth"); err != nil || authCoolie != "true" {
		c.JSON(http.StatusUnauthorized, gin.H{"error": "You are not admin"})
		return
	}
	c.HTML(http.StatusOK, "newArticle.html", gin.H{})
}

func loginAdminGETHandler(c *gin.Context) {
	c.HTML(http.StatusOK, "login.html", gin.H{})
}

func loginAdminMiddleWare(adminPassword string) gin.HandlerFunc {
	return func(c *gin.Context) {
		password := c.PostForm("password")
		if password == adminPassword {
			c.SetCookie("adminAuth", "true", 3600, "/", "", false, true)
			c.Redirect(http.StatusFound, "/admin")
		} else {
			c.HTML(http.StatusUnauthorized, "login.html", gin.H{"error": "Invalid password"})
		}
	}
}

func adminPOSTHandler(c *gin.Context) {
	title := c.PostForm("title")
	content := c.PostForm("content")
	if title == "" || content == "" {
		c.JSON(http.StatusBadRequest, gin.H{"error": "Invalid params"})
		return
	}
	postgresql.PostgreDB.Create(&postgresql.Article{
		Title:   title,
		Content: content,
	})
	c.Redirect(http.StatusFound, "/")
}

func articleHandler(c *gin.Context) {
	var article postgresql.Article
	postgresql.PostgreDB.Where("id = " + c.Param("id")).First(&article)

	c.HTML(http.StatusOK, "article.html", gin.H{
		"title": article.Title,
		"content": template.HTML(
			blackfriday.Run([]byte(article.Content),
				blackfriday.WithExtensions(
					blackfriday.HardLineBreak|
						blackfriday.CommonExtensions,
				),
			)),
	})
}
