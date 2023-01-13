class Solution {
public:
    bool check(string n1, string n2, string num){
        if(n1.size()> 1 && n1[0] == '0' || n2.size() >1 && n2[0]== '0') 
            return false;
        string sum= add(n1, n2);
        if(num ==sum) return true;
        
        if(num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0)
            return false;
        else return check(n2, sum, num.substr(sum.size()));
    }
    
    string add(string a, string b){
        string ans;
        int i = a.size()- 1, j= b.size() -1,carry= 0;
        while(i >= 0 || j>= 0){
            int sum = carry + (i>= 0 ? (a[i--]- '0'): 0) + (j >= 0 ? (b[j--]- '0'): 0);
            
            ans.push_back(sum%10 +'0');
            carry= sum/10;
        }
        if(carry) 
            ans.push_back(carry +'0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool isAdditiveNumber(string num) {
        for(int i= 1; i <= num.size()/2; i++){
            for(int j= 1; j <= (num.size() - i)/2; j++)
                if(check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) return true;
        }
        return false;
    }
};