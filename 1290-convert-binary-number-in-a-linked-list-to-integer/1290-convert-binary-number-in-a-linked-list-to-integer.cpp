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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode *curr = head;
        
        while (curr != NULL){
            ans *= 2;   // ans << 1 (Using bitwise operator)
            ans += (curr->val);
            curr = curr->next;
        }
        
        return ans;
    }
};