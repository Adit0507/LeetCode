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
    bool findTarget(TreeNode* root, int k) {
        vector <int> nums;
        inorder(root, nums);
        
        for(int i=0, j = nums.size() -1; i < j;){
            if(nums[i] + nums[j] == k)
                return true;
            if(nums[i] + nums[j] < k) 
                i++;
            else
                j--;    
        }
        return false;
    }
    
    void inorder(TreeNode* root, vector <int> &nums){
        if(!root)
            return;
        inorder(root ->left, nums);
        nums.push_back(root ->val);
        inorder(root->right, nums);
    }
};