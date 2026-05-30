/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func invertTree(root *TreeNode) *TreeNode {

    if root == nil {
        return nil
    }

    queue := []*TreeNode{root}
    
    for len(queue) > 0 {
        curr := queue[0]
        queue = queue[1:]

        tmp := curr.Right
        curr.Right = curr.Left
        curr.Left = tmp
        
        if curr.Right != nil { queue = append(queue, curr.Right)}
        if curr.Left != nil { queue = append(queue, curr.Left)}
    
    }

    return root 
}
