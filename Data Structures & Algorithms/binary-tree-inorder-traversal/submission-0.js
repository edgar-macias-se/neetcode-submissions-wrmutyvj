/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     constructor(val = 0, left = null, right = null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    /**
     * @param {TreeNode} root
     * @return {number[]}
     */
    inorderTraversal(root) {
        let array=[];
        return this.inOrder(root, array);
    }

    inOrder(node, array){
        if(node==null)
            return array;
        
        this.inOrder(node.left, array)
        array.push(node.val);
        this.inOrder(node.right,array)
        return array;
    }
}
