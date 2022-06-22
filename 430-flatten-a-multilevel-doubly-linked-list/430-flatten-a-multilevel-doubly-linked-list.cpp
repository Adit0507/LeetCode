/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;
        
        Node* curr;
        stack<Node*> stk;
        
        stk.push(head);
        
        Node* newhead = head;
        
        while(!stk.empty()){
            curr = stk.top(); stk.pop();
            
            //go to the end of list or the node having child
            while(curr->next != nullptr && curr->child == nullptr){
                curr = curr->next;
            }
            
            if(curr->next == nullptr && curr->child != nullptr){
                //end node and has child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                
                //need to further visit cur->next
                stk.push(curr->next);
            }else if(curr->next == nullptr){
               
                //go to the end of current level
                if(!stk.empty()){
                    //stk.top() is the node to be concatenated
                    curr ->next = stk.top();
                    stk.top()->prev = curr;
                }
            }else{
                //go to the node having child
                
                //we will later visit its child and then its next
                stk.push(curr->next);
                stk.push(curr->child);
                
                //rewind
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
        }
        return newhead;
    }
};




























