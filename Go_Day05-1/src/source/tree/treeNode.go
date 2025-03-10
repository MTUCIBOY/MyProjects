package tree

func AreToysBalanced(root *TreeNode) bool {
	return countToys(root.Left) == countToys(root.Right)
}

func countToys(root *TreeNode) int {
	if root == nil {
		return 0
	}

	var res int
	if root.Left != nil {
		res += countToys(root.Left)
	}
	if root.Right != nil {
		res += countToys(root.Right)
	}
	res += boolToInt(root.HasToy)
	return res
}

func boolToInt(value bool) int {
	if value {
		return 1
	}
	return 0
}

func UnrollGarland(root *TreeNode) []bool {
	if root == nil {
		return []bool{}
	}

	result := []bool{}
	queue := []*TreeNode{root}
	level := 0

	for len(queue) > 0 {
		size := len(queue)
		levelNodes := []bool{}

		for range size {
			node := queue[0]
			queue = queue[1:]

			levelNodes = append(levelNodes, node.HasToy)

			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		if level%2 == 0 {
			for i, j := 0, len(levelNodes)-1; i < j; i, j = i+1, j-1 {
				levelNodes[i], levelNodes[j] = levelNodes[j], levelNodes[i]
			}
		}

		result = append(result, levelNodes...)
		level++
	}

	return result
}
