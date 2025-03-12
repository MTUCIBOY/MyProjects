package config

import "time"

type Config struct {
	Env        string `env-default:"local" json:"env"`
	StorageDns string `env-required:"true" json:"storage_dns"`
	HTTPServer `json:"http_server"`
}

type HTTPServer struct {
	Address     string        `env-default:"localhost:8888" json:"address"`
	Timeout     time.Duration `env-default:"4s"             json:"timeout"`
	IdleTimeout time.Duration `env-default:"60s"            json:"idle_timeout"`
}
