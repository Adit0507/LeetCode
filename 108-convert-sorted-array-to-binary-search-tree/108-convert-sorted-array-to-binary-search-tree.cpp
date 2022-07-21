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
    TreeNode* bst(vector<int> v, int l, int r){
        if(r - l + 1 <1) return NULL;
        
        int mid = l + (r - l)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root ->left = bst(v,l, mid -1);
        root ->right = bst(v, mid +1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        TreeNode* root = bst(nums, 0, nums.size()-1);
        return root;
    }
};