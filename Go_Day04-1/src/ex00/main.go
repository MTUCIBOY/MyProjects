package main

import (
	"Day4/backServer"
	"log"
	"net/http"
)

func main() {
	http.HandleFunc("/buy_candy", backServer.BuyHandler)
	log.Fatal(http.ListenAndServe(":3333", nil))
}
