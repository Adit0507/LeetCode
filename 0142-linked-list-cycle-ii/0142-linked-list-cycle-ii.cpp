/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast= head, *slow= head;
         while(fast!=NULL && fast->next !=NULL){
             slow= slow->next;
             fast = fast->next->next;
             
             if(fast== slow)
                 break;
         }
        if(fast== NULL || fast->next == NULL) return NULL;
        
        ListNode* p1 = head, *p2= slow;
        while(p1 != p2){
            p1 = p1->next;
            p2= p2->next;
        }
        return p1;
    }
};