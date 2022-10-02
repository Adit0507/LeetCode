class Solution {
public:
    const int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        // dp[i][t] is number of possible ways to roll i dices so the sum of the face up equals t
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int> (target+1, 0));
        dp[0][0] = 1;   // 1 way to roll a dice with with sum 0

        for(int i = 1; i <= n; i++){
            for(int t=1; t <= target; t++){
                for(int j = 1; j <= k; j++)
                    if(j <= t)
                        dp[i][t] = (dp[i][t] + dp[i -1][t -j]) %mod;
            }
        }
        return dp[n][target];
    }
};