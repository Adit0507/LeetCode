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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 1;
        
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            
            ans = max(ans, end - start + 1);
            while(size--){
                auto curr = q.front();
                q.pop();
                long long index = curr.second - start;
                
                if(curr.first->left){
                    q.push({curr.first->left, 2*index + 1});
                }
                if(curr.first->right){
                    q.push({curr.first->right, 2*index + 2});
                }
            }
        }
        return ans;
    }
};



















