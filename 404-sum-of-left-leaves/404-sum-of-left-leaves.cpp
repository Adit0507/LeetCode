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
    int sum = 0;
    void sumOfLeaf(TreeNode* root, bool isLeft){
        if(!root)
            return;
        if(!root->left && !root->right){
            if(isLeft)
                sum += root->val;
            return;
        }
        sumOfLeaf(root->left, true);
        sumOfLeaf(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        sumOfLeaf(root, false);
        return sum;
    }
};