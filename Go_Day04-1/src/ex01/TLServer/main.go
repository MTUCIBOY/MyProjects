package main

import (
	"Day4/backServer"
	"crypto/tls"
	"crypto/x509"
	"log"
	"net/http"
	"os"
)

func main() {
	serverCert, err := tls.LoadX509KeyPair("127.0.0.1/cert.pem", "127.0.0.1/key.pem")
	if err != nil {
		log.Fatal(err)
	}

	caCert, err := os.ReadFile("../minica.pem")
	if err != nil {
		log.Fatal(err)
	}

	caCertPool := x509.NewCertPool()
	caCertPool.AppendCertsFromPEM(caCert)

	tlsConfig := &tls.Config{
		Certificates: []tls.Certificate{serverCert},
		ClientCAs:    caCertPool,
		ClientAuth:   tls.RequireAndVerifyClientCert,
	}

	server := &http.Server{
		Addr:      ":3333",
		TLSConfig: tlsConfig,
	}

	http.HandleFunc("/buy_candy", backServer.BuyHandler)

	log.Println("Сервер запущен на https://127.0.0.1:3333")
	log.Fatal(server.ListenAndServeTLS("", ""))
}
