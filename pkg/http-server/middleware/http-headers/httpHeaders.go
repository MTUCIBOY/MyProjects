package httpheaders

import "net/http"

// SetHeadersMiddleware мидлвейр по настройке заголовков HTTP.
func SetHeadersMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		// Определяет источники ресурсов сайта (только свои в данном случае)
		w.Header().Set("Content_security-Policy", "default-src 'self'; script-src 'self'; style-src 'self';")

		// Говорит браузеру, что подключение к сайту дожно быть только по HTTPS
		w.Header().Set("Strict-Transport-Security", "max-age=3600; includeSubDomains; preload")

		// Запрещает браузеру "угадывать" тип контента, с которым он работает
		w.Header().Set("X-Content-Type-Options", "nosniff")

		// Запрет отрисовки страницы в IFrame
		//
		// Тег iFrame — элемент HTML, позволяющий встраивать на веб-страницу
		// документы, видео и интерактивные медиафайлы и прочие части
		// содержимого из других источников
		w.Header().Set("X-Frame-Options", "DENY")

		// Предотвращает перекрестные атаки на скрипты (XSS)
		w.Header().Set("X-XSS-Protection", "1; mode=block")

		// Не передают никакую информацию в заголовке Reffer, когда сайт
		// переходит с HTTPS на HTTP
		w.Header().Set("Referrer-Policy", "no-referrer-when-downgrade")

		next.ServeHTTP(w, r)
	})
}
