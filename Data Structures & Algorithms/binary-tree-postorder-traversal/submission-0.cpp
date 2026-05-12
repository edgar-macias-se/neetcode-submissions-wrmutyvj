/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*,bool>> pila;
        pila.push(make_pair(root, false));

        while(!pila.empty()){
            pair<TreeNode*, bool> curr = pila.top(); pila.pop();

            if(curr.first){
                if(!curr.second){
                    pila.push(make_pair(curr.first, true));
                    pila.push(make_pair(curr.first->right, false));
                    pila.push(make_pair(curr.first->left, false));
                } else {
                    res.push_back(curr.first->val);
                }
            }
            
        }

        return res;
        
    }
};