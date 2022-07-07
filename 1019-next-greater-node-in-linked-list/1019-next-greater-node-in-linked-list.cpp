/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> res;
        stack <int> st;
        while(head){
            res.push_back(head->val);
            head = head->next;
        }
        
        for(int i= res.size()-1; i >= 0; i--){
            int val = res[i];
            
            while(!st.empty() && st.top() <= res[i])
                st.pop();
            
            res[i] = st.empty() ? 0: st.top();
            st.push(val);
        }
        return res;
    }
};









