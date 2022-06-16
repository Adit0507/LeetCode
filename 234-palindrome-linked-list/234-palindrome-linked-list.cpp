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
    ListNode* reverseList(ListNode* head){
        if(head == NULL)
            return NULL;
        
        ListNode *p = NULL, *curr = head, *n = head->next;
        
        while(curr != NULL){
            curr->next = p;
            p = curr;
            curr = n;
            
            if(n!= NULL) 
                n = n->next;
        }
        return p;
    }
    
    void print(ListNode *head){
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;   
    }
        
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast=head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        ListNode* start = head, *mid = slow->next;
        
        
        while(mid != NULL){
            if(mid->val != start->val)
                return false;
            start = start->next;
            mid = mid->next;
        }
        
        print(head);
        
        return true;
    }
};