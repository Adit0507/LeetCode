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
    string serialize(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*> &ans){
        if(!root) return "";
        
        string sub = to_string(root->val) + ',' + serialize(root->left, m, ans) + "," + serialize(root->right, m, ans);
        
        if(++m[sub] == 2)
            ans.push_back(root);
        
        return sub;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> m;
        
        if(!root) return ans;
        
        string tree = serialize(root, m, ans);
        return ans;
    }
};