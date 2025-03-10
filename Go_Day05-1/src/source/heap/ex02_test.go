package heap

import (
	"errors"
	"testing"
)

func TestEx02(t *testing.T) {
	t.Run("nil slice", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents(nil, 0)
		if len(resGot) != 0 {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, []Present{})
		}
		if errGot != nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, nil)
		}
	})
	t.Run("invalid n 1", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents([]Present{}, 1)
		if len(resGot) != 0 {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, []Present{})
		}
		if errGot == nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, errors.New("Invalid n parameter"))
		}
	})
	t.Run("invalid n 2", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents([]Present{}, -1)
		if len(resGot) != 0 {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, []Present{})
		}
		if errGot == nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, errors.New("Invalid n parameter"))
		}
	})
	t.Run("slice 1 len", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents([]Present{{5, 5}}, 1)
		wantSlice := Present{5, 5}
		if resGot[0] != wantSlice {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, wantSlice)
		}
		if errGot != nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, nil)
		}
	})
	t.Run("slice 2 len", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents([]Present{{3, 3}, {5, 5}}, 1)
		wantSlice := Present{5, 5}
		if resGot[0] != wantSlice {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, wantSlice)
		}
		if errGot != nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, nil)
		}
	})
	t.Run("slice 2 len 2 n", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents([]Present{{3, 3}, {5, 5}}, 2)
		wantSlice := []Present{{5, 5}, {3, 3}}
		for i := range wantSlice {
			if resGot[i] != wantSlice[i] {
				t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, wantSlice)
				break
			}
		}
		if errGot != nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, nil)
		}
	})
	t.Run("slice 3 len 1 n", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents([]Present{{3, 3}, {5, 5}, {2, 10}}, 1)
		wantSlice := []Present{{5, 5}}
		for i := range wantSlice {
			if resGot[i] != wantSlice[i] {
				t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, wantSlice)
				break
			}
		}
		if errGot != nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, nil)
		}
	})
	t.Run("README example", func(t *testing.T) {
		resGot, errGot := GetNCoolestPresents([]Present{{5, 1}, {4, 5}, {3, 1}, {5, 2}}, 2)
		wantSlice := []Present{{5, 1}, {5, 2}}
		for i := range wantSlice {
			if resGot[i] != wantSlice[i] {
				t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", resGot, wantSlice)
				break
			}
		}
		if errGot != nil {
			t.Errorf("GetNCoolestPresents: Got: %v, Want: %v\n", errGot, nil)
		}
	})
}
