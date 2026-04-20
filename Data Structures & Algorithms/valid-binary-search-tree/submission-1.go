/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type QueueItem struct {
    node *TreeNode
    left int64
    right int64
}

func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }

    queue := []QueueItem{{root, math.MinInt64, math.MaxInt64}}

    for len(queue) > 0 {
        item := queue[0]
        queue = queue[1:]

        val := int64(item.node.Val)
        if val <= item.left || val >= item.right {
            return false
        }

        if item.node.Left != nil {
            queue = append(queue, QueueItem{item.node.Left, item.left, val})
        }
        if item.node.Right != nil {
            queue = append(queue, QueueItem{item.node.Right, val, item.right})
        }
    }

    return true
}