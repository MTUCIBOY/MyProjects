package heap

import "testing"

func TestEx03(t *testing.T) {
	t.Run("nil slice", func(t *testing.T) {
		got := GrabPresents(nil, 0)
		want := []Present{}
		for i := range want {
			if got[i] != want[i] {
				t.Errorf("GrabPresents: got: %v != want: %v", got, nil)
				break
			}
		}
	})
	t.Run("zero cap", func(t *testing.T) {
		got := GrabPresents([]Present{{5, 5}, {3, 3}}, 0)
		want := []Present{}
		for i := range want {
			if got[i] != want[i] {
				t.Errorf("GrabPresents: got: %v != want: %v", got, nil)
				break
			}
		}
	})
	t.Run("1 cap", func(t *testing.T) {
		got := GrabPresents([]Present{{5, 5}, {3, 3}}, 1)
		want := []Present{}
		for i := range want {
			if got[i] != want[i] {
				t.Errorf("GrabPresents: got: %v != want: %v", got, nil)
				break
			}
		}
	})
	t.Run("16 cap", func(t *testing.T) {
		got := GrabPresents([]Present{{3, 5}, {3, 3}}, 16)
		want := []Present{{3, 3}}
		for i := range want {
			if got[i] != want[i] {
				t.Errorf("GrabPresents: got: %v != want: %v", got, nil)
				break
			}
		}
	})
	t.Run("17 cap", func(t *testing.T) {
		got := GrabPresents([]Present{{3, 5}, {3, 3}}, 17)
		want := []Present{{3, 3}}
		for i := range want {
			if got[i] != want[i] {
				t.Errorf("GrabPresents: got: %v != want: %v", got, nil)
				break
			}
		}
	})
	t.Run("README example", func(t *testing.T) {
		got := GrabPresents([]Present{{5, 1}, {4, 5}, {3, 1}, {5, 2}}, 32)
		want := []Present{{5, 1}, {5, 2}}
		for i := range want {
			if got[i] != want[i] {
				t.Errorf("GrabPresents: got: %v != want: %v", got, nil)
				break
			}
		}
	})
}
