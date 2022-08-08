class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j= 0; j < i; j++)
                if(nums[i] > nums[j] && ans[i] < ans[j] + 1)
                    ans[i] = ans[j] + 1;
        }
        return *max_element(ans.begin(), ans.end());
    }
};