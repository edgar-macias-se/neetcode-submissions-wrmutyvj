/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func maxDepth(root *TreeNode) int {
   
   var result int
   var dfs func(node *TreeNode) int
   
   dfs = func(node *TreeNode) int {
        if node == nil {
            return result
        }

        return 1 + max(dfs(node.Right), dfs(node.Left))
   }

   return dfs(root)
}

func max(a,b int) int {
    if a > b {
        return a
    }

    return b
}