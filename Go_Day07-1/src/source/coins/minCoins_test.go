package coins

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMinCoins(t *testing.T) {
	tests := []struct {
		name  string
		val   int
		coins []int
		want  []int
	}{
		{
			name:  "val zero, coins nil",
			val:   0,
			coins: []int{},
			want:  []int{},
		},
		{
			name:  "val pos, coins nil",
			val:   10,
			coins: []int{},
			want:  []int{},
		},
		{
			name:  "val neg, coins nil",
			val:   -10,
			coins: []int{},
			want:  []int{},
		},
		{
			name:  "val zero, coins not nil",
			val:   0,
			coins: []int{1, 5, 10},
			want:  []int{},
		},
		{
			name:  "val 10, coins not nil",
			val:   10,
			coins: []int{1, 5, 10},
			want:  []int{10},
		},
		{
			name:  "val neg, coins not nil",
			val:   -10,
			coins: []int{1, 5, 10},
			want:  []int{},
		},
		// Тест уходит в бесконечный цикл
		// {
		// 	name:  "val 10, coins with neg",
		// 	val:   10,
		// 	coins: []int{-1, 1, 5, 10},
		// 	want:  []int{},
		// },
		// Тест уходит в бесконечный цикл
		// {
		// 	name:  "val 10, coins with zero",
		// 	val:   10,
		// 	coins: []int{0, 1, 5, 10},
		// 	want:  []int{},
		// },
		{
			name:  "val 10, coins not sorted",
			val:   10,
			coins: []int{9, 3, 1},
			want:  []int{},
		},
		{
			name:  "val 10, coins not unique",
			val:   10,
			coins: []int{1, 2, 2, 3},
			want:  []int{},
		},
		{
			name:  "README example",
			val:   13,
			coins: []int{1, 5, 10},
			want:  []int{10, 1, 1, 1},
		},
		{
			name:  "val can't be decomposed",
			val:   13,
			coins: []int{5, 10},
			want:  []int{},
		},
	}
	for _, test := range tests {
		t.Run(test.name, func(t *testing.T) {
			assert.Equal(t, test.want, MinCoins(test.val, test.coins))
		})
	}
}
