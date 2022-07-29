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
    void path(vector<string>&res, TreeNode* root, string t){
        if(!root->left && !root->right){
            res.push_back(t);
            return;
        }
        if(root->left) path(res, root->left, t + "->"+ to_string(root->left->val));
        if(root->right)
            path(res, root->right, t+ "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        
        path(ans, root, to_string(root->val));
        return ans;
    }
};