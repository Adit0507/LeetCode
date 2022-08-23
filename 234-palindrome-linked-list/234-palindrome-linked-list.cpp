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
        if(head ==NULL) return NULL;
        
        ListNode* a= NULL, *curr = head;
        ListNode* n = head->next;
        
        while(curr){
            curr ->next = a;
            a = curr;
            curr = n;
            
            if(n)
                n = n->next;
        }
        return a;    
    }
    
    void print(ListNode* head){
        while(head){
            cout <<head->val << " ";
            head = head->next;
        }
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast = head;
        
        while(fast ->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow ->next = reverseList(slow->next);
        ListNode* start = head;
        ListNode* mid = slow->next;
        
        while(mid){
            if(mid->val != start->val)
                return false;
            
            start = start->next;
            mid = mid->next;
        }
        
        print(head);
        return true;
    }
};