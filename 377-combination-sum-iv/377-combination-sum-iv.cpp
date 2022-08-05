class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target +1, -1);
        return solve(nums, nums.size(), target, dp);
    }
    int solve(vector<int> &arr, int len, int target, vector<int> &dp){
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int i=0; i < len; i++){
            ans += solve(arr, len, target -arr[i], dp);
        }
        return dp[target] = ans;
    }
};