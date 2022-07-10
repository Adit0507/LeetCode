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
    int ans;
    void sum(TreeNode* node, bool isLeft){
    
        if(node->left == NULL && node->right == NULL && isLeft){
            ans+= node->val;
        }    
        if(node->left){
            sum(node->left, true);
        }
        if(node->right){
            sum(node->right, false);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        ans = 0;      
        sum(root, false);
        
        return ans;
    }
};