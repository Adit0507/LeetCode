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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        
        ListNode* prev= new ListNode (-1);
        ListNode* dummy = prev;
        ListNode* curr = head;
        
        prev->next = curr;
        
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                while(curr->next && curr->val == curr->next->val ){
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

















