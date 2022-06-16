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
    void reverse(ListNode *s, ListNode * e)
    {
        ListNode *p = NULL, *curr = s, *n = s->next;
        
        while(p != e)
        {
            curr->next = p;
            p = curr;
            curr = n;
            
            if(n != NULL)
                n =n->next; 
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL || head->next == NULL || k ==1) 
            return head;
        
        ListNode *s = head, *e = head;  // Start and End pointer
        
        int inc =  k - 1;
        
        while(inc --){
            e = e->next;
            if(e == NULL) return head; 
        }
        
        ListNode* nextHead = reverseKGroup(e->next, k);    
        reverse(s, e);
        s->next = nextHead;
        
        return e;
    }
};