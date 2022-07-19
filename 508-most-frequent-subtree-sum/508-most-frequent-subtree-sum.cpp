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
    int subTree(TreeNode* root, unordered_map<int, int> &mp){
        if(root == NULL)
            return 0;
        int lSub = subTree (root->left, mp);
        int rSub = subTree (root->right, mp);
        
        int sub = lSub + rSub + root->val;
        
        if(mp.find(sub) != mp.end()){
            mp[sub] ++;            
        }else {
            mp.insert({sub, 1});
        }
        return sub;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> M;
        subTree(root, M);
        
        int fmax = INT_MIN;
        for(auto it: M){
            if(it.second > fmax)
                fmax = it.second;
        }
        for(auto it:M){
            if(it.second == fmax)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};


















