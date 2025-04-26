package httpheaders

import "net/http"

func SetHeadersMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content_security-Policy", "default-src 'self'; script-src 'self'; style-src 'self';")

		w.Header().Set("Strict-Transport-Security", "max-age=3600; includeSubDomains; preload")

		w.Header().Set("X-Content-Type-Options", "nosniff")

		w.Header().Set("X-Frame-Options", "DENY")

		w.Header().Set("X-XSS-Protection", "1; mode=block")

		w.Header().Set("Referrer-Policy", "no-referrer-when-downgrade")

		next.ServeHTTP(w, r)
	})
}
