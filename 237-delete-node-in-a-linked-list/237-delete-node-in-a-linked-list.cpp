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
    void deleteNode(ListNode* node) {
        
        if(node->next == NULL)  // Checking if the node is last or not
            delete node;
        
        //         
        swap(node->val, node->next-> val);
        ListNode *temp = node ->next;   // Node which is to be deleted
        node->next = node->next->next;  // temp-> next can also be written
        delete temp;
    }
};