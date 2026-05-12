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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> pila;
        TreeNode* curr = root;

        while(curr || !pila.empty()){
            if(curr){
                result.push_back(curr->val);
                if(curr->right){
                    pila.push(curr->right);
                }
                curr = curr->left;
            } else {
                curr = pila.top();
                pila.pop();
            }   
        }

        return result;
    }
};