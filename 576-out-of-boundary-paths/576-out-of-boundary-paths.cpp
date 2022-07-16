class Solution {
public:
    int Paths(int m, int n, int N, int R, int C, vector<vector<vector<int>>>&dp){
        if(R < 0 || R >= m || C < 0 || C >= n)
            return 1;
        if(N == 0) return 0;
        if(dp[R][C][N] != -1) 
            return dp[R][C][N];
        int mod = 1e9 + 7;

        return dp[R][C][N]=((Paths(m,n,N-1,R+1,C,dp)+Paths(m,n,N-1,R-1,C,dp))%mod+(Paths(m,n,N-1,R,C+1,dp)+Paths(m,n,N-1,R,C-1,dp))%mod)%mod;

    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove +1,-1)));
    
        return Paths(m, n, maxMove, startRow, startColumn, dp);
    }
};