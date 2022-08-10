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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n ==0) return NULL;
        if(n ==1)   
            return new TreeNode(nums[0]);
        int mid = n/2;
        TreeNode* root= new TreeNode(nums[mid]);
        vector<int> l(nums.begin(), nums.begin() + mid);
        vector<int> r(nums.begin() + mid +1, nums.end());
        
        root ->left = sortedArrayToBST(l);
        root->right = sortedArrayToBST(r);
        
        return root;
    }
};