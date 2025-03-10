// Code generated by protoc-gen-go-grpc. DO NOT EDIT.
// versions:
// - protoc-gen-go-grpc v1.5.1
// - protoc             v5.29.2
// source: protoFiles/proto/transmitter.proto

package proto

import (
	context "context"
	grpc "google.golang.org/grpc"
	codes "google.golang.org/grpc/codes"
	status "google.golang.org/grpc/status"
)

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
// Requires gRPC-Go v1.64.0 or later.
const _ = grpc.SupportPackageIsVersion9

const (
	Transmitter_StreamFrequency_FullMethodName = "/transmitter.Transmitter/StreamFrequency"
)

// TransmitterClient is the client API for Transmitter service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://pkg.go.dev/google.golang.org/grpc/?tab=doc#ClientConn.NewStream.
//
// Определяем сервис
type TransmitterClient interface {
	// Метод, который будет стримить данные клиенту
	// Клиент отправляет один запрос, а сервер отвечает потоком данных
	StreamFrequency(ctx context.Context, in *StreamRequest, opts ...grpc.CallOption) (grpc.ServerStreamingClient[FrequencyData], error)
}

type transmitterClient struct {
	cc grpc.ClientConnInterface
}

func NewTransmitterClient(cc grpc.ClientConnInterface) TransmitterClient {
	return &transmitterClient{cc}
}

func (c *transmitterClient) StreamFrequency(ctx context.Context, in *StreamRequest, opts ...grpc.CallOption) (grpc.ServerStreamingClient[FrequencyData], error) {
	cOpts := append([]grpc.CallOption{grpc.StaticMethod()}, opts...)
	stream, err := c.cc.NewStream(ctx, &Transmitter_ServiceDesc.Streams[0], Transmitter_StreamFrequency_FullMethodName, cOpts...)
	if err != nil {
		return nil, err
	}
	x := &grpc.GenericClientStream[StreamRequest, FrequencyData]{ClientStream: stream}
	if err := x.ClientStream.SendMsg(in); err != nil {
		return nil, err
	}
	if err := x.ClientStream.CloseSend(); err != nil {
		return nil, err
	}
	return x, nil
}

// This type alias is provided for backwards compatibility with existing code that references the prior non-generic stream type by name.
type Transmitter_StreamFrequencyClient = grpc.ServerStreamingClient[FrequencyData]

// TransmitterServer is the server API for Transmitter service.
// All implementations must embed UnimplementedTransmitterServer
// for forward compatibility.
//
// Определяем сервис
type TransmitterServer interface {
	// Метод, который будет стримить данные клиенту
	// Клиент отправляет один запрос, а сервер отвечает потоком данных
	StreamFrequency(*StreamRequest, grpc.ServerStreamingServer[FrequencyData]) error
	mustEmbedUnimplementedTransmitterServer()
}

// UnimplementedTransmitterServer must be embedded to have
// forward compatible implementations.
//
// NOTE: this should be embedded by value instead of pointer to avoid a nil
// pointer dereference when methods are called.
type UnimplementedTransmitterServer struct{}

func (UnimplementedTransmitterServer) StreamFrequency(*StreamRequest, grpc.ServerStreamingServer[FrequencyData]) error {
	return status.Errorf(codes.Unimplemented, "method StreamFrequency not implemented")
}
func (UnimplementedTransmitterServer) mustEmbedUnimplementedTransmitterServer() {}
func (UnimplementedTransmitterServer) testEmbeddedByValue()                     {}

// UnsafeTransmitterServer may be embedded to opt out of forward compatibility for this service.
// Use of this interface is not recommended, as added methods to TransmitterServer will
// result in compilation errors.
type UnsafeTransmitterServer interface {
	mustEmbedUnimplementedTransmitterServer()
}

func RegisterTransmitterServer(s grpc.ServiceRegistrar, srv TransmitterServer) {
	// If the following call pancis, it indicates UnimplementedTransmitterServer was
	// embedded by pointer and is nil.  This will cause panics if an
	// unimplemented method is ever invoked, so we test this at initialization
	// time to prevent it from happening at runtime later due to I/O.
	if t, ok := srv.(interface{ testEmbeddedByValue() }); ok {
		t.testEmbeddedByValue()
	}
	s.RegisterService(&Transmitter_ServiceDesc, srv)
}

func _Transmitter_StreamFrequency_Handler(srv interface{}, stream grpc.ServerStream) error {
	m := new(StreamRequest)
	if err := stream.RecvMsg(m); err != nil {
		return err
	}
	return srv.(TransmitterServer).StreamFrequency(m, &grpc.GenericServerStream[StreamRequest, FrequencyData]{ServerStream: stream})
}

// This type alias is provided for backwards compatibility with existing code that references the prior non-generic stream type by name.
type Transmitter_StreamFrequencyServer = grpc.ServerStreamingServer[FrequencyData]

// Transmitter_ServiceDesc is the grpc.ServiceDesc for Transmitter service.
// It's only intended for direct use with grpc.RegisterService,
// and not to be introspected or modified (even as a copy)
var Transmitter_ServiceDesc = grpc.ServiceDesc{
	ServiceName: "transmitter.Transmitter",
	HandlerType: (*TransmitterServer)(nil),
	Methods:     []grpc.MethodDesc{},
	Streams: []grpc.StreamDesc{
		{
			StreamName:    "StreamFrequency",
			Handler:       _Transmitter_StreamFrequency_Handler,
			ServerStreams: true,
		},
	},
	Metadata: "protoFiles/proto/transmitter.proto",
}
