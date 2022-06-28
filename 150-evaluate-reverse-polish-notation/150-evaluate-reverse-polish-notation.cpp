class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        
        for(string x:tokens){
            if (x == "+"){
                int a = s.top(); // a =2
                s.pop();
                int b = s.top(); //b = 3
                // a + b = 2+3 
                s.pop();
                s.push(a + b);
            }
            else if(x == "*"){
                int a = s.top(); // a =2
                s.pop();
                int b = s.top(); //b = 3
                // a + b = 2+3 
                s.pop();
                s.push(a * b);
            }
            else if(x == "-"){
                int a = s.top(); // a =2
                s.pop();
                int b = s.top(); //b = 3
                // b-a = 1
                s.pop();
                s.push(b - a);
            }
            else if(x == "/"){
                int a = s.top(); // a =2
                s.pop();
                int b = s.top(); //b = 3
                 
                s.pop();
                s.push(b/a);
            }
            else 
                s.push(stoi(x));
        }
        return s.top();
    }
};