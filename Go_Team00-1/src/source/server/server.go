package server

import (
	"fmt"
	"log"
	"math/rand/v2"
	"net"
	"time"

	"github.com/google/uuid"
	"google.golang.org/grpc"

	pb "Team00/protoFiles/gen/transmitter/proto"
)

// Структура gRPC сервера
type server struct {
	_grpsServer *grpc.Server
	_port       int
	pb.UnimplementedTransmitterServer
}

// Функция генерации UUID
func generateUUID() string {
	return uuid.New().String()
}

// Функция генерации мат. ожидания
func generateMean() float64 {
	return rand.Float64()*20 - 10
}

// Функция генерации ср-квад. отклонения
func generateDeviation() float64 {
	return rand.Float64()*1.2 + 0.3
}

// Функция генерации частоты
func generateFrequency(mean, deviation float64) float64 {
	return rand.NormFloat64()*deviation + mean
}

// Метод стриминга частоты из proto-файла
func (s *server) StreamFrequency(
	req *pb.StreamRequest,
	stream grpc.ServerStreamingServer[pb.FrequencyData],
) error {
	sessionID := generateUUID()
	mean := generateMean()
	deviation := generateDeviation()

	log.Printf(
		"New session: ID=%s, Mean=%.2f, deviation=%.2f",
		sessionID,
		mean,
		deviation,
	)

	for {
		frequency := generateFrequency(mean, deviation)
		timestamp := time.Now().Unix()

		data := &pb.FrequencyData{
			SessionId: sessionID,
			Frequency: frequency,
			Timestamp: timestamp,
		}

		if err := stream.Send(data); err != nil {
			log.Printf("Error sending data: %v", err)
			return err
		}

		time.Sleep(100 * time.Millisecond)
	}
}

// Создание нового сервера
func NewServer(port int) *server {
	return &server{
		_grpsServer: grpc.NewServer(),
		_port:       port,
	}
}

// Запуск сервера
func (s *server) Run() {
	lis, err := net.Listen("tcp", fmt.Sprintf("localhost:%d", s._port))
	if err != nil {
		log.Fatal(err)
	}

	pb.RegisterTransmitterServer(s._grpsServer, &server{})

	log.Println("Server is running")

	if err := s._grpsServer.Serve(lis); err != nil {
		log.Fatal(err)
	}
}
