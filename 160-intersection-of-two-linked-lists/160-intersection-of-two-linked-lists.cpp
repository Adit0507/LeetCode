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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B = headB;
        
        while(A != B){
            if(A == NULL)
                A = headB;
            else 
                A= A->next;
            
            if(B == NULL)
                B = headA;
           else B = B->next;
        }
        return A;
    }
};