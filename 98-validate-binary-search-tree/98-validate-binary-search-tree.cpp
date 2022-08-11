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
    bool isValidBST(TreeNode* root) {
        long min = LONG_MIN;
        stack <TreeNode* > s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root ->left;
            }
            root = s.top();
            s.pop();
            
            if(root->val <=min)
                return false;
            
            min = root->val;
            root = root->right;
        }
        return true;
    }
};