class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(string x: tokens){
            if(x== "+"){
                int a= s.top();
                s.pop();
                
                int b= s.top();
                s.pop();
                s.push(a + b);
            }
            else if(x== "*"){
                long a = s.top(); 
                s.pop();

                long b = s.top(); 
                s.pop();
                s.push(a*b);
            }
            else if(x== "-"){
                int a= s.top();
                s.pop();
                
                int b= s.top();
                s.pop();
                s.push(b- a);
            }
            else if(x== "/"){
                int a= s.top();
                s.pop();
                
                int b= s.top();
                s.pop();
                s.push(b/a);
            }
            else
                s.push(stoi(x));
        }
        return s.top();
    }
};