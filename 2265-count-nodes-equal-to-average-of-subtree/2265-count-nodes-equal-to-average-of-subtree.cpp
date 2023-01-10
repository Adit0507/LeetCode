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
    int ans= 0;
    int sum(TreeNode* root, int &c){
        if(!root) return 0;
        c++;
        int l= sum(root->left, c);
        int r= sum(root->right, c);
        return (root->val + l +r);
    }
    void solve(TreeNode* root){
        if(!root) return ;
        int c= 0;
        int avg = sum(root, c)/c;
        if(avg== root->val)
            ans ++;
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};










































