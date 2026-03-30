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
     * @return {TreeNode}
     */
    invertTree(root) {

        if (!root) return null;
        
        let stack = [];

        stack.push(root);

        while(stack.length > 0){
            let currNode = stack.pop();
            [currNode.left, currNode.right] = [currNode.right, currNode.left]
            if(currNode.left) stack.push(currNode.left)
            if(currNode.right) stack.push(currNode.right)
        }
        return root;
    }
}
