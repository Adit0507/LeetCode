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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL)
            return NULL;
        
        ListNode *current = head, *prev = NULL;
        
        while(left > 1){
            prev = current;
            current = current->next;
            left --;
            right --;
        }
        
        ListNode *tailPrev = prev, *tail =current, *i = NULL;
        
        while(right > 0){
            i = current->next;
            current->next = prev;
            prev = current;
            current = i;
            right --;
        }
        
        if(tailPrev != NULL){
            tailPrev->next = prev;
        } 
        else {
            head = prev;
        }
        
        tail->next = current;
        
        return head;
    }
};