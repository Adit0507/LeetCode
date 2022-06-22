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
    ListNode* prev = new ListNode(-1);
    ListNode* dummy = prev;
    ListNode* cur = head;
    prev->next = cur;
    while(cur && cur->next) {
        if(cur->val == cur->next->val) {
            while(cur->next && cur->val==cur->next->val) {
                ListNode* tmp = cur;
                cur = cur->next;
                delete (tmp);
            }
            prev->next = cur->next;
            delete (cur);
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy->next;
    }
};