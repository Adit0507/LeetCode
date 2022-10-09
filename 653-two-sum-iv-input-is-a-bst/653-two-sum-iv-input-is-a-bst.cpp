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
    void inorder(TreeNode* root, int k, vector<int> &arr){
        if(!root)
            return;
        inorder(root->left, k, arr);
        arr.push_back(root->val);
        inorder(root->right, k, arr);
    }
    bool findTarget(TreeNode* root, int k) {
       vector<int> arr;
       inorder(root, k, arr);
       int i = 0,j= arr.size() -1;
       while(i < j){
           int sum = arr[i] + arr[j];
           if(sum ==k) 
               return true;
           sum > k ? j-- : i++;
       }
       return false;
    }
};