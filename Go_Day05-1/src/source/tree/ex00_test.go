package tree

import (
	"testing"
)

func TestEx00(t *testing.T) {
	var tr BTree
	tr.New()

	t.Run("Left and Right nil", func(t *testing.T) {
		res := AreToysBalanced(tr.Root())
		if !res {
			t.Errorf("result is false, want true!")
		}
	})
	tr.AddLeftNode(false)
	t.Run("Left is false, Right nil", func(t *testing.T) {
		res := AreToysBalanced(tr.Root())
		if !res {
			t.Errorf("result is false, want true!")
		}
	})
	tr.AddRightNode(true)
	t.Run("Left is false, Right is true", func(t *testing.T) {
		res := AreToysBalanced(tr.Root())
		if res {
			t.Errorf("result is true, want false!")
		}
	})
	tr.GoLeftNode()
	tr.AddRightNode(true)
	tr.ReturnToRoot()
	t.Run("Deep Left, Right is true", func(t *testing.T) {
		res := AreToysBalanced(tr.Root())
		if !res {
			t.Errorf("result is false, want true!")
		}
	})
	tr.GoRightNode()
	tr.AddLeftNode(true)
	tr.AddRightNode(false)
	tr.ReturnToRoot()
	t.Run("Deep Left, Deep Right", func(t *testing.T) {
		res := AreToysBalanced(tr.Root())
		if res {
			t.Errorf("result is true, want false!")
		}
	})
}

func TestEx00FromReadMe(t *testing.T) {
	t.Run("first", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.AddLeftNode(false)
		tr.AddRightNode(true)
		tr.GoLeftNode()
		tr.AddLeftNode(false)
		tr.AddRightNode(true)
		tr.ReturnToRoot()
		res := AreToysBalanced(tr.Root())

		if !res {
			t.Errorf("result is false, want true!")
		}
	})
	t.Run("second", func(t *testing.T) {
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
		tr.ReturnToRoot()
		res := AreToysBalanced(tr.Root())

		if !res {
			t.Errorf("result is false, want true!")
		}
	})
	t.Run("third", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.SetValue(true)
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		tr.ReturnToRoot()
		res := AreToysBalanced(tr.Root())

		if res {
			t.Errorf("result is true, want false!")
		}
	})
	t.Run("fourth", func(t *testing.T) {
		var tr BTree
		tr.New()
		tr.AddLeftNode(true)
		tr.AddRightNode(false)
		tr.GoLeftNode()
		tr.AddRightNode(true)
		tr.GoBack()
		tr.GoRightNode()
		tr.AddRightNode(true)
		tr.ReturnToRoot()
		res := AreToysBalanced(tr.Root())

		if res {
			t.Errorf("result is true, want false!")
		}
	})
}

func TestEx00BigTree(t *testing.T) {
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
	tr.ReturnToRoot()

	res := AreToysBalanced(tr.Root())

	if !res {
		t.Errorf("result is false, want true!")
	}
}
