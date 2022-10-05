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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth ==1){
           TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        bool done = false;
        while(!q.empty()){
            int n = q.size();
            
            while(n --){
                TreeNode* cur = q.front();
                q.pop();
                if(level == depth -1){
                    if(cur->left){
                        TreeNode* l = cur->left;
                        cur->left = new TreeNode(val);
                        cur->left->left = l;
                    }else{
                        cur->left = new TreeNode(val);
                    }
                    if(cur->right){
                        TreeNode* r= cur->right;
                        cur->right = new TreeNode(val);
                        cur->right->right = r;
                    }else{
                        cur->right = new TreeNode(val);
                    }
                    done = true;
                }else{
                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                }
            }
            level++;
            if(done) break;
        }
        return root;
    }
};




























