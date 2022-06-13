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
    ListNode* reverse(ListNode *head)
    {
        if(head->next == NULL){
            return head;
        }
        
        ListNode *reverseHead = reverse(head->next);
        head->next-> next = head;       // head->next->next ko wapas head pe
        head-> next = NULL;             // Reverse hone ke liye head->next ko NULL hona parega
        
        return reverseHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        return reverse (head);
    }
};