class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1, (vector<int>(s2.size() +1, 0)));
        if(s3.size() != s1.size() + s2.size()){
            return false;
        }
        for(int i=s1.size(); i >= 0; i--){
            for(int j =s2.size(); j >= 0; j--){
                int k = i + j;
                if(i == s1.size() && j==s2.size()){
                    dp[i][j] = 1;
                }
                else if(s3[k] ==s2[j] && s3[k] == s1[i]){
                    dp[i][j] = dp[i+1][j] || dp[i][j +1];
                }
                else if(s1[i] == s3[k]){
                    dp[i][j] = dp[i+1][j];
                }
                else if(s3[k] == s2[j]){
                    dp[i][j] = dp[i][j +1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[0][0];
    }
};