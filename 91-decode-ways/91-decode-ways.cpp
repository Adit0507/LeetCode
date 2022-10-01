class Solution {
public:
    int memo[100] = {};
    int numDecodings(string s) {
        return dp(s, 0);
    }
    int dp(const string &s, int i){
        int ans = 0;
        if(i == s.size())
            return 1;
        if(memo[i] != 0) return memo[i];
        if(s[i] != '0')
            ans += dp(s, i + 1);
        if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i +1] <= '6'))
            ans += dp(s, i +2);
        return memo[i] = ans;
    }
};