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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        
        ListNode* curr = head;
        
        // Length
        int len =1;
        while(curr->next && len++)
            curr = curr->next;
        
        // Selected node
        curr->next = head;
        k = k % len;    // Doing this to keep k in limit
        k = len - k;
        while(k--) curr = curr->next;
        
        // make the node head and break the connection
        head = curr->next;
        curr->next = NULL;
        
        return head;
    }
};