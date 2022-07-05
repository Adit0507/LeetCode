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
    int rec(TreeNode* root, int mx){    //Address of node and max. value
        if(!root) return 0;
        
        int curr = 0;
        if(mx <= root->val)
            curr++;
        mx = max(mx, root->val);
        return rec(root->left, mx) + rec(root->right, mx) + curr;
    }
    
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        return rec(root, mx);
    }
};




















