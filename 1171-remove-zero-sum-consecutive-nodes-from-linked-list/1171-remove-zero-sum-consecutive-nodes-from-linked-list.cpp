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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == NULL) return NULL;
        
        unordered_map <int, ListNode*> m;
        ListNode* dummy = new ListNode (0);
        dummy ->next = head;
        
        m[0] = dummy;
        int prefixSum = 0;
        
        while (head)
        {
            prefixSum += head->val;
            
            if(m.find(prefixSum) != m.end())
            {
                ListNode* start = m[prefixSum];
                int sum = prefixSum;
                
                while (start != NULL && start != head){
                    start = start->next;
                    sum += start->val;
                    
                    if (start != head)
                        m.erase(sum);
                }
                m[prefixSum] ->next = head->next;
            }
            else {
                m[prefixSum] = head;
            }
            head = head ->next;
        }
        
        return dummy->next;
    }
};

















