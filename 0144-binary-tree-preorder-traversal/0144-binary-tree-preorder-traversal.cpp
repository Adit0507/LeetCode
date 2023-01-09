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
        vector<int> nodes;
        stack<TreeNode*> t;
        while(!t.empty()|| root){
            if(root){
                nodes.push_back(root->val);
                if(root->right)
                    t.push(root->right);
                root= root->left;
            } else{
                root= t.top();
                t.pop();
            }
        }
        return nodes;
    }
};