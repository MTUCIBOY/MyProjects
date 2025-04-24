// TODO: When project will be done, change MustLoad func

// Пакет config нужен для работы с конфигурацией облачного сервера.
// Пакет использует конфиги в формате YAML.
// Зависит от стороннего пакета cleanenv для более удобной работы с тегами структуры и парсинга конфиг-файла.
package config

import (
	"log"
	"os"
	"time"

	"github.com/ilyakaznacheev/cleanenv"
)

// Config Структура исходных настроек облачного сервера.
type Config struct {
	// Переменная окружения.
	// Обычно ставится как local, но в перспективе может быть как debug и prod.
	// Нужна для разного уровня логирования.
	Env string `env-default:"local" yaml:"env"`

	// Переменная для подключения к базе данных.
	// Используется в PGX PostgresSQL.
	// Если строка пустая, но приложение не запустится.
	StorageDSN string `env-required:"true" yaml:"storage_dsn"`

	// Переменная, задающая время жизни JWT.
	TokenTTL time.Duration `env-required:"true" yaml:"token_ttl"`

	// Переменная пути сертификата.
	CertPath string `env-required:"true" yaml:"cert_path"`

	// Переменная пути приватного ключа.
	KeyPath string `env-required:"true" yaml:"key_path"`

	// Настройки HTTP-сервера.
	HTTPServer `yaml:"http_server"`
}

// HTTPServer Структура настроек сервера.
type HTTPServer struct {
	// Адресс, на котором будет запускаться приложение.
	// Обычно - localhost:8888.
	Address string `env-default:"localhost:8888" yaml:"address"`

	// Время на чтение запроса и отправку ответа.
	Timeout time.Duration `env-default:"4s" yaml:"timeout"`

	// Время жизни соединения с клиентом.
	IdleTimeout time.Duration `env-default:"60s" yaml:"idle_timeout"`
}

// MustLoad Функция парсинга конфигурационного файла.
// Путь до файла читается из переменной окружения CONFIG_PATH.
// В случае любой ошибки, приложение падает.
func MustLoad() *Config {
	configPath := os.Getenv("CONFIG_PATH")
	if configPath == "" {
		// log.Fatal("CONFIG_PATH is not set")
		configPath = "/home/pain/MyProjects/config/local.yml"
	}

	if _, err := os.Stat(configPath); os.IsNotExist(err) {
		log.Fatalf("config file does not exist: %s", configPath)
	}

	var cfg Config
	if err := cleanenv.ReadConfig(configPath, &cfg); err != nil {
		log.Fatalf("failed parse config file: %v", err)
	}

	return &cfg
}
