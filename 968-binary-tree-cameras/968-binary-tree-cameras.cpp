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
    int ans = 0;
public:
    int traversal(TreeNode* node){
        if(!node) return 0;
        int val = traversal(node->left) + traversal(node->right);
        if(val == 0) return 3;
        if(val < 3) return 0;
        ans++;
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        return traversal(root) > 2 ?ans +1: ans;
    }
};