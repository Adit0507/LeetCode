class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target, nums.size());
    }
    
    unsigned int solve(vector<int>arr, int target, int l){
        vector<unsigned int> dp(target +1, 0);
        // for target 0 ans is 1
        dp[0] =1;
        // traversing ebery target
        for(int i=1; i <= target; i++){
            // traversing array
            for(int j =0; j< l; j++){
                //check if the target is going -ve
                if(i - arr[j] >= 0)
                    dp[i] += dp[i - arr[j]];
            }
        }
        return dp[target];        
    }
};