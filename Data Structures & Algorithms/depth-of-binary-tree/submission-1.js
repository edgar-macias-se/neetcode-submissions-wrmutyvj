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
     * @return {number}
     */
    maxDepth(root) {
        
        if(!root) return 0;
        
        let road = new Map();
        let q = [root];
        let control = 0;

        while(control < q.length){
            let currNode = q[control];
            if(currNode.left){
                q.push(currNode.left);
                road.set(currNode.left, currNode)
            }
               
            if(currNode.right){
                q.push(currNode.right);
                road.set(currNode.right, currNode)
            }
            
            control++;
        }
        
        let lastVisited = q.pop();
        let res = 1;
        while(lastVisited!=root){
            lastVisited=road.get(lastVisited);
            res++;
        }

        
        return res;
    }
}
