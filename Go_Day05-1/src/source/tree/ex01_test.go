package tree

import "testing"

func TestEx01(t *testing.T) {
	t.Run("only root", func(t *testing.T) {
		var tr BTree
		tr.New()
		got := UnrollGarland(tr.Root())
		want := []bool{false}
		for i, element := range got {
			if want[i] != element {
				t.Errorf("UnrollGarland: slice not equal. Got: %v; Want: %v", got, want)
				break
			}
		}
	})
	t.Run("one node", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.SetValue(true)
		tr.AddLeftNode(true)
		got := UnrollGarland(tr.Root())
		want := []bool{true, true}
		for i, element := range got {
			if want[i] != element {
				t.Errorf("UnrollGarland: slice not equal. Got: %v; Want: %v", got, want)
				break
			}
		}
	})
	t.Run("two nodes", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.SetValue(false)
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		got := UnrollGarland(tr.Root())
		want := []bool{false, true, false}
		for i, element := range got {
			if want[i] != element {
				t.Errorf("UnrollGarland: slice not equal. Got: %v; Want: %v", got, want)
				break
			}
		}
	})
	t.Run("three nodes", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.SetValue(false)
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		tr.GoLeftNode()
		tr.AddLeftNode(true)
		tr.ReturnToRoot()
		got := UnrollGarland(tr.Root())
		want := []bool{false, true, false, true}
		for i, element := range got {
			if want[i] != element {
				t.Errorf("UnrollGarland: slice not equal. Got: %v; Want: %v", got, want)
				break
			}
		}
	})
	t.Run("README example", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.SetValue(true)
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		tr.GoLeftNode()
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		tr.GoBack()
		tr.GoRightNode()
		tr.AddLeftNode(true)
		tr.AddRightNode(true)
		got := UnrollGarland(tr.Root())
		want := []bool{true, true, false, true, true, false, true}
		for i, element := range got {
			if want[i] != element {
				t.Errorf("UnrollGarland: slice not equal. Got: %v; Want: %v", got, want)
				break
			}
		}
	})
	t.Run("Big Tree", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		tr.GoLeftNode()
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		tr.GoRightNode()
		tr.AddLeftNode(true)
		tr.GoBack()
		tr.GoLeftNode()
		tr.AddRightNode(true)
		tr.GoRightNode()
		tr.AddLeftNode(false)
		tr.AddRightNode(true)
		tr.GoBack()
		tr.GoBack()
		tr.GoBack()
		tr.GoRightNode()
		tr.AddLeftNode(true)
		tr.AddRightNode(true)
		tr.GoLeftNode()
		tr.AddLeftNode(true)
		tr.GoBack()
		tr.GoRightNode()
		tr.AddLeftNode(false)
		tr.AddRightNode(false)
		tr.GoLeftNode()
		tr.AddLeftNode(true)
		tr.GoBack()
		tr.GoRightNode()
		tr.AddLeftNode(false)
		tr.AddRightNode(true)
		got := UnrollGarland(tr.Root())
		want := []bool{false, true, false, true, true,
			false, true, true, true, true, false, false,
			true, false, true, true, false}
		for i, element := range got {
			if want[i] != element {
				t.Errorf("UnrollGarland: slice not equal. Got: %v; Want: %v", got, want)
				break
			}
		}
	})

}
