package source

import (
	"errors"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEx00(t *testing.T) {
	slice := []int{1, 2, 3, 4, 5, 6}
	nilSlice := []int{}
	table := []struct {
		name    string
		slice   []int
		inx     int
		wantInt int
		wantErr error
	}{
		{
			name:    "slice nil, index zero",
			slice:   nilSlice,
			inx:     0,
			wantInt: 0,
			wantErr: errors.New("slice is empty"),
		},
		{
			name:    "slice nil, index not zero",
			slice:   nilSlice,
			inx:     10,
			wantInt: 0,
			wantErr: errors.New("slice is empty"),
		},
		{
			name:    "slice not nil, index neg",
			slice:   slice,
			inx:     -1,
			wantInt: 0,
			wantErr: errors.New("index out of range"),
		},
		{
			name:    "slice not nil, index gt len slice",
			slice:   slice,
			inx:     len(slice),
			wantInt: 0,
			wantErr: errors.New("index out of range"),
		},
		{
			name:    "slice not nil, index in range",
			slice:   slice,
			inx:     0,
			wantInt: 1,
			wantErr: nil,
		},
		{
			name:    "slice not nil, index in range",
			slice:   slice,
			inx:     1,
			wantInt: 2,
			wantErr: nil,
		},
		{
			name:    "slice not nil, index in range",
			slice:   slice,
			inx:     len(slice) - 1,
			wantInt: 6,
			wantErr: nil,
		},
	}

	for _, obj := range table {
		gotInt, gotErr := getElement(obj.slice, obj.inx)
		assert.Equal(t, gotInt, obj.wantInt)
		assert.Equal(t, obj.wantErr, gotErr)
	}
}
