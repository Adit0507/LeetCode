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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int >> q;
        q.push({root, 0});
        
        while(q.size()){
            auto [n, curr]= q.front();
            q.pop();
            curr = curr*10 + n->val;
            if(n->left) 
                q.push({n->left, curr});
            if(n->right) 
                q.push({n->right, curr});
            if(!n->left && !n->right)
                sum += curr;
        }
        return sum;
    }
};