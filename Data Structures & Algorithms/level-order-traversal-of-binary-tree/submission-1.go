/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func levelOrder(root *TreeNode) [][]int {

    var res [][]int

    if root == nil {
        return [][]int{}
    }

    q := []*TreeNode{}
    q = append(q, root)

    
     for len(q) > 0 {
        var level []int

        for _, el := range(q) {

            node := q[0]
            q = q[1:len(q)]

            if node != nil {
                level = append(level, node.Val)
                q = append(q, el.Left)
                q = append(q, el.Right)
            }   
        }

        if len(level) > 0 {
            res = append(res, level)
        }

     }

     return res
}
