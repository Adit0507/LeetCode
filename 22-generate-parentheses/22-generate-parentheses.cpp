class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        addingPar(ans,"", n, 0);
        return ans;
    }
    void addingPar(vector <string> &v, string str, int n, int m){
        if(n  == 0 && m ==0){
            v.push_back(str);
            return ;
        }
        
        if(m > 0) {addingPar(v, str + ")", n, m -1);}
        if(n > 0){addingPar(v, str + "(", n - 1, m + 1);}
    }
};