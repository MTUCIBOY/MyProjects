package main

import (
	"Day4/backServer"
	"bytes"
	"crypto/tls"
	"crypto/x509"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
)

var moneyFlag = flag.Int("m", 0, "money")
var candyCount = flag.Int("c", 0, "number of candy")
var candyType = flag.String("k", "", "type of candy")

func main() {
	clientCert, err := tls.LoadX509KeyPair("127.0.0.1/cert.pem", "127.0.0.1/key.pem")
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
		Certificates: []tls.Certificate{clientCert},
		RootCAs:      caCertPool,
	}

	client := &http.Client{
		Transport: &http.Transport{
			TLSClientConfig: tlsConfig,
		},
	}

	flag.Parse()

	req := backServer.RequestBody{
		Money:      *moneyFlag,
		CandyType:  *candyType,
		CandyCount: *candyCount,
	}
	reqJSON, err := json.Marshal(req)
	if err != nil {
		log.Fatal(err)
	}

	resp, err := client.Post("https://127.0.0.1:3333/buy_candy", "json", bytes.NewReader(reqJSON))
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Print(string(body))
}
