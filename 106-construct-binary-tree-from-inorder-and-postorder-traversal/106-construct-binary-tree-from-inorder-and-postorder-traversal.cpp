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
    TreeNode* constructTree(vector<int>&postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &m) {
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int ele = m[root->val];
        int nEle = ele - inStart;
        
        root->left = constructTree(postorder, postStart, postStart + nEle -1, inorder, inStart, ele -1, m);
        root->right = constructTree(postorder, postStart + nEle, postEnd -1, inorder, ele + 1, inEnd, m);
        
        return root;
    }
        
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart =0, postEnd = postorder.size() -1;
        int inStart = 0, inEnd = inorder.size() -1;
        
        map<int, int> m;
        for(int i=inStart; i <= inEnd; i++){
            m[inorder[i]] = i;
        }
        return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, m);
    }
};

