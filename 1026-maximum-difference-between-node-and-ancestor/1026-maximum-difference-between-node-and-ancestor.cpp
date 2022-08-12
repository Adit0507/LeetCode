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
    void maxDiff(TreeNode* root, int Max, int Min, int &diff){
        if(root==NULL)
            return;
        Max= max(Max, root->val);
        Min = min(Min, root ->val);
        
        diff = max(Max - Min, diff);
        
        maxDiff(root->left, Max, Min, diff);
        maxDiff(root->right, Max, Min, diff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int Max = INT_MIN, Min = INT_MAX, diff = INT_MIN;
        
        maxDiff(root, Max, Min, diff);
        
        return diff;
    }
};