class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back()== '1') return false;
        vector<bool>dp(s.size());
        dp[0] = true;
        int n= s.size();
        int c = 0;
        for(int i =1; i < n; i++){
            if(i > maxJump)
                c -= dp[i-maxJump -1];
            if(i >=minJump)
                c += dp[i -minJump];
            
            if(c >0 && s[i]== '0') dp[i]= true;
            else
                dp[i]= false;
        }
        return dp.back();
    }
};