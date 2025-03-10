package tree

import "container/list"

type TreeNode struct {
	HasToy bool
	Left   *TreeNode
	Right  *TreeNode
}

type BTree struct {
	root     *TreeNode
	current  *TreeNode
	previous *list.List
}

func (b *BTree) New() {
	b.root = &TreeNode{
		HasToy: false,
		Left:   nil,
		Right:  nil,
	}
	b.current = b.root
	b.previous = list.New()
}

func (b *BTree) Root() *TreeNode {
	return b.root
}

func (b *BTree) AddLeftNode(value bool) bool {
	if b.current.Left != nil {
		return false
	}
	b.current.Left = &TreeNode{
		HasToy: value,
		Left:   nil,
		Right:  nil,
	}
	return true
}

func (b *BTree) AddRightNode(value bool) bool {
	if b.current.Right != nil {
		return false
	}
	b.current.Right = &TreeNode{
		HasToy: value,
		Left:   nil,
		Right:  nil,
	}
	return true
}

func (b *BTree) GoLeftNode() bool {
	if b.current.Left == nil {
		return false
	}
	b.previous.PushBack(b.current)
	b.current = b.current.Left
	return true
}

func (b *BTree) GoRightNode() bool {
	if b.current.Right == nil {
		return false
	}
	b.previous.PushBack(b.current)
	b.current = b.current.Right
	return true
}

func (b *BTree) ReturnToRoot() {
	b.current = b.root
	b.previous = b.previous.Init()
}

func (b *BTree) GoBack() bool {
	if b.previous.Len() == 0 {
		return false
	}
	b.current = b.previous.Back().Value.(*TreeNode)
	b.previous.Remove(b.previous.Back())
	return true
}

func (b *BTree) SetValue(value bool) {
	b.current.HasToy = value
}

func (b *BTree) Value() bool {
	return b.current.HasToy
}

func (b *BTree) NewWithRoot(root *TreeNode) {
	b.root = root
	b.current = b.root
	b.previous = list.New()
}
