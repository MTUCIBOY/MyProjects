package database

import (
	"Team00/source/database/models"
	"fmt"
	"log"

	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)


type Config struct {
	Host string
	Port int
	User string
	Password string
	DBName string
}

type Database struct {
	db *gorm.DB
}

// NewDatabase создает новое подключение к базе данных
func NewDatabase(config Config) (*Database, error) {
	dsn := fmt.Sprintf(
        "host=%s port=%d user=%s password=%s dbname=%s sslmode=disable",
        config.Host, config.Port, config.User, config.Password, config.DBName,
    )

	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{})
	if err != nil {
        return nil, fmt.Errorf("failed to connect to database: %w", err)
    }

	// Автоматическая миграция таблиц
	if err := db.AutoMigrate(&models.Anomaly{}); err != nil {
        return nil, fmt.Errorf("failed to migrate database: %w", err)
    }

	return &Database{db: db}, nil	
}

// SaveAnomaly сохраняет информацию об аномалии в базу данных
func (d *Database) SaveAnomaly(sessionID string, frequency float64, timestamp int64) error {
	anomaly := models.Anomaly{
		SessionID: sessionID,
		Frequency: frequency,
		Timestamp: timestamp,
	}

	if err := d.db.Create(&anomaly).Error; err != nil {
        return fmt.Errorf("failed to save anomaly: %w", err)
    }

	log.Printf("Saved anomaly: SessionID=%s, Frequency=%f", sessionID, frequency)
    return nil
}

func (d *Database) Close() error {
    sqlDB, err := d.db.DB()
    if err != nil {
        return err
    }
    return sqlDB.Close()
}

