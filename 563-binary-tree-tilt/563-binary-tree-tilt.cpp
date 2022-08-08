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
    int Sum = 0;
    int findTilt(TreeNode* root) {
        dfs(root);
        return Sum;
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int lSum = dfs(root ->left);
        int rSum = dfs(root ->right);
        Sum += abs(lSum - rSum);
        
        return lSum + rSum + root->val;
    }
};