package main

import (
	"Team00/source/client"
	"Team00/source/database"
	"flag"
	"log"
	"os"
	"os/signal"
	"syscall"
)

var anomalyFlag = flag.Float64("k", 3.0, "Anomaly coefficient")

func main() {
	flag.Parse()

	if *anomalyFlag < 0 {
		log.Fatal("k can't be negative")
	}

	dbConfig := database.Config{
		Host:     "localhost",
		Port:     5433,
		User:     "postgres",
		Password: "postgres",
		DBName:   "anomalies",
	}

	db, err := database.NewDatabase(dbConfig)
	if err != nil {
		log.Fatal(err)
	}

	// Отложенное закрытие соединения с БД
    defer func() {
        if err := db.Close(); err != nil {
            log.Printf("Error closing database connection: %v", err)
        }
    }()

    // Канал для обработки сигналов
    sigChan := make(chan os.Signal, 1)
    signal.Notify(sigChan, syscall.SIGINT, syscall.SIGTERM)

    // Запускаем клиент в отдельной горутине
    done := make(chan struct{})
    go func() {
        c := client.NewClient("localhost:1337", *anomalyFlag, db)
        c.Run()
        close(done)
    }()

    // Ожидаем либо завершения клиента, либо сигнала
    select {
    case <-done:
        log.Println("Client finished normally")
    case sig := <-sigChan:
        log.Printf("Received signal: %v, shutting down...", sig)
    }
}
