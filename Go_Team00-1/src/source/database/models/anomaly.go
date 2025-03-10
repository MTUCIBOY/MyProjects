package models

import "time"

type Anomaly struct {
	ID        uint    `gorm:"primaryKey"`
	SessionID string  `gorm:"not null;index"`
	Frequency float64 `gorm:"not null"`
	Timestamp int64   `gorm:"not null"`
	CreatedAt time.Time `gorm:"not null"`
}