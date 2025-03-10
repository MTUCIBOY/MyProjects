genProtoFiles:
	protoc --go_out=protoFiles/gen --go-grpc_out=protoFiles/gen protoFiles/proto/transmitter.proto

launchServer:
	go run cmd/server/main.go

launchClient:
	go run cmd/client/main.go