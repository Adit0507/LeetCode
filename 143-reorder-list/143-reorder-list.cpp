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
    ListNode* reverse(ListNode* head){
        ListNode* prev= NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        
        while(curr){
            nxt = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        // Finding the middle of the LL using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reversing the 2nd half and splitting the list in two
        ListNode* second = reverse(slow -> next); // slow->next is Head of the 2nd Linked List
        
        slow->next = NULL; // To break the connection to make 2 LL
        
        ListNode* first = head; // First list
        
        // Merging the 2 lists
        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second ->next;
            
            first -> next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};












