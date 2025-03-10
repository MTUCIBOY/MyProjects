package source

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEx01(t *testing.T) {
	table := []any{
		0, 1, -1,
		0.0, 1.0, -1.0,
		[]int{}, map[string]string{},
		struct{}{}, UnknownPlant{},
		UnknownPlant{
			FlowerType: "flower",
			LeafType:   "beauty",
			Color:      10,
		},
		AnotherUnknownPlant{},
		AnotherUnknownPlant{
			FlowerColor: 10,
			LeafType:    "lanceolate",
			Height:      15,
		},
	}

	for _, obj := range table {
		assert.NotPanics(t, func() {
			fmt.Println("Chech", obj)
			DescribePlant(obj)
			fmt.Println()
		})
	}
}
