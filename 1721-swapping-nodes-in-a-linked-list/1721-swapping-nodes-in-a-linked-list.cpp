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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        
        vector <int> v;
        int count =0;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;    
            count++;
        }
        
        swap(k-1, count - k, v);
        int i = 0;
        while(temp2){
            temp2->val = v[i];
            i++;
            temp2 = temp2->next;
        }
        return head;
    }
    void swap(int i, int j, vector<int>&v)
    {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }    
};






















