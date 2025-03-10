package db

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"strconv"
	"strings"
	"time"

	"github.com/golang-jwt/jwt/v5"
)

var key = []byte("123")

// Через curl: curl -H "Authorization: Bearer <your-token>" "http://127.0.0.1:8888/api/recommend?lat=55.75&lon=37.61"

func UpAPI() {
	var d ElasticSearchStore
	if err := d.NewESClient(); err != nil {
		log.Fatal(err)
	}
	// d.UpCSVDataBase()
	// time.Sleep(time.Millisecond * 1000)
	upGenerateToken(1)

	upProtectedRecomend(Store(&d))

	http.ListenAndServe("localhost:8888", nil)
}

type TokenStruct struct {
	Token string `json:"token"`
}

func upGenerateToken(id int) {
	http.HandleFunc("/api/get_token", func(w http.ResponseWriter, r *http.Request) {
		token := jwt.NewWithClaims(jwt.SigningMethodHS256, jwt.MapClaims{
			"id":  id,
			"exp": time.Now().Add(time.Hour).Unix(),
		})
		tokenString, err := token.SignedString(key)
		if err != nil {
			http.Error(w, "Failed to generate token", http.StatusInternalServerError)
			return
		}
		w.Header().Set("Content-Type", "application/json")
		if err := json.NewEncoder(w).Encode(TokenStruct{Token: tokenString}); err != nil {
			http.Error(w, "Failed to encode response", http.StatusInternalServerError)
			return
		}
	})
}

func upProtectedRecomend(s Store) {
	res := struct {
		Name   string  `json:"name"`
		Places []Place `json:"places"`
	}{
		Name: "Recommendation",
	}
	recHandler := func(w http.ResponseWriter, r *http.Request) {
		latPage := r.URL.Query().Get("lat")
		if latPage == "" {
			latPage = "0"
		}
		lonPage := r.URL.Query().Get("lon")
		if lonPage == "" {
			lonPage = "0"
		}

		lat, err := strconv.ParseFloat(latPage, 64)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Invalid 'page' value: 'foo'\"\n}",
				http.StatusBadRequest,
			)
			return
		}
		lon, err := strconv.ParseFloat(lonPage, 64)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Invalid 'page' value: 'foo'\"\n}",
				http.StatusBadRequest,
			)
			return
		}

		res.Places = s.GetRecommendationByLoc(lat, lon)
		if res.Places == nil {
			http.Error(
				w, "{\n\t\"error\": \"Internal server error\"\n}",
				http.StatusInternalServerError,
			)
			return
		}

		jsonRespond, err := json.Marshal(res)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Internal server error\"\n}",
				http.StatusInternalServerError,
			)
			return
		}

		w.Header().Set("Content-Type", "application/json")
		w.Write(jsonRespond)
	}

	http.HandleFunc("/api/recommend", jwtMiddleware(recHandler))
}

func jwtMiddleware(next http.HandlerFunc) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		authHeader := r.Header.Get("Authorization")
		if authHeader == "" {
			http.Error(w, "Authorization header is required", http.StatusUnauthorized)
			return
		}
		if !strings.HasPrefix(authHeader, "Bearer ") {
			http.Error(w, "Invalid authorization header format", http.StatusUnauthorized)
			return
		}
		tokenString := strings.TrimPrefix(authHeader, "Bearer ")
		token, err := jwt.Parse(tokenString, func(token *jwt.Token) (interface{}, error) {
			if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
				return nil, fmt.Errorf("unexpected signing method: %v", token.Header["alg"])
			}
			return key, nil
		})
		if err != nil || !token.Valid {
			http.Error(w, "Invalid or expired token", http.StatusUnauthorized)
			return
		}

		next(w, r)
	}
}
