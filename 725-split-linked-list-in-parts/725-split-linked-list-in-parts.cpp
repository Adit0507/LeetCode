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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;
        while(curr){
            n++;
            curr = curr->next;
        }
        
        int width = n/k, rem = n%k;
        
        vector<ListNode* >ans(k, NULL);
        
        curr = head;
        for(int i =0; i < k; i++){
            ListNode* prev = curr;
            ListNode* head= curr;
            
            for(int j=0; j < width + (i < rem ? 1:0) -1; j++){
                if(prev)
                    prev = prev->next;
            }
            if(prev){
                curr = prev->next;
                prev->next = NULL;
            }
            ans[i] = head;
        }
        return ans;
    }
};














