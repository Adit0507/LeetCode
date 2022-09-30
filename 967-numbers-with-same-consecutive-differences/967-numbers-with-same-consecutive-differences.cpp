class Solution {
public:
    vector <int> ans;   
    void solve(int i, int n, int k){
        // all digits done, push the anseer
        if(n ==0){
            ans.push_back(i);
            return ;
        }
        // Subtract k
        if(i% 10 -k >= 0){
            int num = i*10 + (i% 10 - k);
            solve(num, n -1, k);
        }
        // Add k
        if(i %10 + k <=9 && (k!=0)){
            int num = i*10 + (i% 10 + k);       
            solve(num, n-1, k);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1; i <= 9; i++){
            solve(i, n -1, k);
        }
        return ans;
    }
};      