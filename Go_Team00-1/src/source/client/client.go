package client

import (
	"context"
	"errors"
	"io"
	"log"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"

	pb "Team00/protoFiles/gen/transmitter/proto"
	"Team00/source/database"
)

// Структура gRPC клиента
type client struct {
	// Адресс, к которому будет подключаться клиент
	address string
	// Статистика анализатора
	Data *analyzeData
	db *database.Database
}

// Метод подключения клиента к серверу
func (c *client) Run() {
	conn, err := grpc.NewClient(
		c.address,
		grpc.WithTransportCredentials(insecure.NewCredentials()),
	)
	if err != nil {
		log.Fatal(err)
	}
	defer conn.Close()
	log.Println("Client is connected")

	clc := pb.NewTransmitterClient(conn)
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()

	stream, err := clc.StreamFrequency(ctx, &pb.StreamRequest{})
	if err != nil {
		log.Fatal(err)
	}

	c.fillingData(stream)
	c.startAnalysis(stream)
}

// Метод заполнения данных из потока
func (c *client) fillingData(
	stream grpc.ServerStreamingClient[pb.FrequencyData],
) {
	log.Println("Starting filling data")

	for i := 0; i < 50; i++ {
		resp, err := stream.Recv()
		if err == io.EOF {
			log.Println("Stream is OVER")
			break
		}
		if err != nil {
			log.Fatal(err)
		}

		frequency := resp.Frequency
		c.Data.AddNewValue(frequency)
		log.Printf("Add new value: %f\n", frequency)
		log.Println(c.Data)
	}

	log.Println("Finishing filling data")
}

// Метод нахождения аномалий в потоке
func (c *client) startAnalysis(
	stream grpc.ServerStreamingClient[pb.FrequencyData],
) {
	log.Println("Starting analysing data")

	for {
		resp, err := stream.Recv()
		if check := c.Data.IsAnomaly(resp.Frequency); check {
			log.Printf("Anomaly found: %f\n", resp.Frequency)
			if err := c.db.SaveAnomaly(resp.SessionId, resp.Frequency, resp.Timestamp); err != nil {
				log.Printf("Failed to save anomaly: %v", err)
			}
		}
		if errors.Is(err, io.EOF) {
			log.Println("Stream is OVER")
			break
		}
		if err != nil {
			log.Fatal(err)
		}
	}

	log.Println("Finishing analysing data")
}

// Функция создания нового клиента
func NewClient(address string, anomalyCof float64, db *database.Database) *client {
	return &client{
		address: address,
		Data: &analyzeData{
			anomaly: anomalyCof,
		},
		db: db,
	}
}
