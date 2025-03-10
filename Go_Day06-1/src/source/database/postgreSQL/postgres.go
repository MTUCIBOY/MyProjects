package postgresql

import (
	"log"
	"time"

	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

type Article struct {
	ID        uint `grom:"primaryKey"`
	Title     string
	Content   string
	CreatedAt time.Time
	UpdatedAt time.Time
}

var PostgreDB *gorm.DB

func InitDB() {
	dsn := "host=localhost user=postgres password=postgres dbname=blog port=5432 sslmode=disable"
	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{})
	if err != nil {
		log.Fatal(err)
	}
	PostgreDB = db
	PostgreDB.AutoMigrate(&Article{})
}
