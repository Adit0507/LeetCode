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
    void allPathSum(TreeNode* root, int targetSum, vector<int> v, vector<vector<int>> &ans){
        if(!root)
            return;
        targetSum -= root->val;
        v.push_back(root->val);
        if(!root->right && !root->left){
            if(targetSum == 0)
                ans.push_back(v);
            return;
        }
        allPathSum(root->left, targetSum, v, ans);
        allPathSum(root->right, targetSum, v, ans);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        vector<vector<int>> ans;
        allPathSum(root, targetSum, v, ans);
        return ans;
    }
};












