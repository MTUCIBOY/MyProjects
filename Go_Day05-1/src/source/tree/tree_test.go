package tree

import "testing"

func TestBTreeInit(t *testing.T) {
	var tr BTree
	tr.New()
	if tr.root == nil ||
		tr.previous.Len() != 0 ||
		tr.current != tr.root ||
		tr.current.HasToy ||
		tr.current.Left != nil ||
		tr.root.Right != nil {
		t.Errorf("Failed init BTree: %v", tr)
	}
}

func TestBTreeAddNode(t *testing.T) {
	var tr BTree
	tr.New()
	t.Run("Add left node", func(t *testing.T) {
		resp := tr.AddLeftNode(false)
		if !resp || tr.current != tr.root ||
			tr.previous.Len() != 0 ||
			tr.current.Left == nil ||
			tr.current.Right != nil ||
			tr.current.Left.HasToy {
			t.Errorf("Failed add new left node!")
		}
	})
	t.Run("Add right node", func(t *testing.T) {
		resp := tr.AddRightNode(false)
		if !resp || tr.current != tr.root ||
			tr.previous.Len() != 0 ||
			tr.current.Right == nil ||
			tr.current.Right.HasToy {
			t.Errorf("Failed add new right node!")
		}
	})
	t.Run("Add left node, when left node exist", func(t *testing.T) {
		resp := tr.AddLeftNode(true)
		if resp || tr.current != tr.root ||
			tr.previous.Len() != 0 ||
			tr.current.Left == nil ||
			tr.current.Left.HasToy {
			t.Errorf("Failed adding, when left node exists")
		}
	})
	t.Run("Add left node, when left node exist", func(t *testing.T) {
		resp := tr.AddRightNode(true)
		if resp || tr.current != tr.root ||
			tr.previous.Len() != 0 ||
			tr.current.Right == nil ||
			tr.current.Right.HasToy {
			t.Errorf("Failed adding, when left node exists")
		}
	})
}

func TestBTreeGo(t *testing.T) {
	var tr BTree
	tr.New()
	t.Run("Go left nil", func(t *testing.T) {
		resp := tr.GoLeftNode()
		if resp ||
			tr.current != tr.root ||
			tr.previous.Len() != 0 {
			t.Errorf("Going left node")
		}
	})
	t.Run("Go back nil", func(t *testing.T) {
		resp := tr.GoBack()
		if resp ||
			tr.current != tr.root ||
			tr.previous.Len() != 0 {
			t.Errorf("Failed going back")
		}
	})
	t.Run("Go right nil", func(t *testing.T) {
		resp := tr.GoRightNode()
		if resp ||
			tr.current != tr.root ||
			tr.previous.Len() != 0 {
			t.Errorf("Going right node")
		}
	})

	tr.AddLeftNode(true)
	tr.AddRightNode(false)

	t.Run("Go left", func(t *testing.T) {
		resp := tr.GoLeftNode()
		if !resp ||
			tr.current == tr.root ||
			tr.previous.Len() != 1 ||
			tr.previous.Back().Value.(*TreeNode) != tr.root {
			t.Errorf("Failed going left node")
		}
	})
	t.Run("Go back", func(t *testing.T) {
		resp := tr.GoBack()
		if !resp ||
			tr.current != tr.root ||
			tr.previous.Len() != 0 {
			t.Errorf("Failed going back")
		}
	})
	t.Run("Go right", func(t *testing.T) {
		resp := tr.GoRightNode()
		if !resp ||
			tr.current == tr.root ||
			tr.previous.Len() != 1 ||
			tr.previous.Back().Value.(*TreeNode) != tr.root {
			t.Errorf("Failed going right node")
		}
	})
	tr.AddRightNode(false)
	t.Run("Go right deep", func(t *testing.T) {
		resp := tr.GoRightNode()
		if !resp ||
			tr.current == tr.root ||
			tr.previous.Len() != 2 {
			t.Errorf("Failed going deep right node")
		}
	})
	t.Run("Return to root", func(t *testing.T) {
		tr.ReturnToRoot()
		if tr.current != tr.root ||
			tr.previous.Len() != 0 {
			t.Errorf("Failed to return to root")
		}
	})
}

func TestBTreeGetters(t *testing.T) {
	var tr BTree
	tr.New()

	t.Run("In new tree", func(t *testing.T) {
		if tr.Value() {
			t.Errorf("After init HasToy is true!: %v", tr.root.HasToy)
		}
	})
	t.Run("Changed tree", func(t *testing.T) {
		tr.SetValue(true)

		if !tr.Value() {
			t.Errorf("After init HasToy is false!: %v", tr.root.HasToy)
		}
	})
	t.Run("Get root", func(t *testing.T) {
		if tr.Root() == nil {
			t.Errorf("After init root is nil!")
		}
	})
}