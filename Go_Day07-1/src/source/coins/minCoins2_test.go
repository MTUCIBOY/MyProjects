package coins

import (
	"math/rand"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMinCoins2(t *testing.T) {
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
		{
			name:  "val 10, coins with neg",
			val:   10,
			coins: []int{-1, 1, 5, 10},
			want:  []int{},
		},
		{
			name:  "val 10, coins with zero",
			val:   10,
			coins: []int{0, 1, 5, 10},
			want:  []int{},
		},
		{
			name:  "val 10, coins not sorted",
			val:   10,
			coins: []int{9, 3, 1},
			want:  []int{9, 1},
		},
		{
			name:  "val 10, coins not unique",
			val:   10,
			coins: []int{1, 2, 2, 3},
			want:  []int{3, 3, 3, 1},
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
			assert.Equal(t, test.want, MinCoins2(test.val, test.coins))
		})
	}
}

func BenchmarkMinCoins2(b *testing.B) {
	input := []int{}
	for range 100 {
		input = append(input, rand.Intn(1000))
	}
	for b.Loop() {
		_ = MinCoins2(rand.Intn(1000000), input)
	}
}
