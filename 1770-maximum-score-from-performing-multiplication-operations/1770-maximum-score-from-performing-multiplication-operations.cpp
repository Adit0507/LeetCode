class Solution {
public:
    int dp[1001][1001];
    int findScore(int idx, vector<int>& nums, vector<int>& multipliers, int l){
        if(idx == multipliers.size())
            return 0;
        
        if(dp[idx][l] != INT_MIN)
            return dp[idx][l];
        
        int r = nums.size() - (idx - l) -1;
        int score1 = multipliers[idx]*nums[l] + findScore(idx +1, nums, multipliers, l + 1);
        int score2 = multipliers[idx]*nums[r] + findScore(idx +1, nums, multipliers, l);
        return dp[idx][l] = max(score1, score2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(int i = 0; i < 1001; i++){
            for(int j =0; j < 1001; j++){
                dp[i][j] = INT_MIN;
            }
        }
        return findScore(0, nums, multipliers, 0);
    }
};