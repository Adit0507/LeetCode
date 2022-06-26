class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector <int> counter(26, 0);
        
        // To store the answer
        stack <char> st;
        
        
        // To check whether a char is added in the stack or not
        vector<bool> seen(26, false);
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            ++counter[s[i] - 'a'];
        }
        
        for(char& c: s){
            --counter[c - 'a'];
            
            // Skip duplicate
            if(seen[c - 'a'])
                continue;
            
            while(!st.empty() && c < st.top() && counter[st.top() - 'a'] > 0){
                char topc = st.top();
                st.pop();
                seen[topc - 'a'] = false;
            }
            
            st.push(c);
            seen[c - 'a'] = true;
        }
        
        string ans;
        
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};























