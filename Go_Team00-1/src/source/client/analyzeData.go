package client

import (
	"fmt"
	"math"
)

// Структура для анализа потока
type analyzeData struct {
	// Количество прочтенных данных
	countData uint64
	// Среднее арифметическое
	mean float64
	// Дисперсия (нужна для расчета ср-квад. отклонения)
	variance float64
	// Ср-квад. отклонение
	deviation float64
	// Коэффициент аномалии
	anomaly float64
}

// Добавление новой статистики по из потока
func (a *analyzeData) AddNewValue(value float64) {
	a.countData++
	oldMean := a.mean

	// Новое среднее
	a.mean += (value - a.mean) / float64(a.countData)
	// Новая дисперсия
	a.variance += (value - oldMean) * (value - a.mean)
	// Новое отклонение
	a.deviation = math.Sqrt(a.variance / float64(a.countData))
}

// Проверка на аномалию
func (a *analyzeData) IsAnomaly(value float64) bool {
	return math.Abs(value-a.mean) > a.anomaly*a.deviation
}

// Для красивого вывода
func (a analyzeData) String() string {
	return fmt.Sprintf(
		"DataCount: %d\tMean: %f\tDeviation: %f",
		a.countData,
		a.mean,
		a.deviation,
	)
}
