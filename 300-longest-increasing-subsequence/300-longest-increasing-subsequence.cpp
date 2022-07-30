class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> ans(nums.size(), 1);
        
        for(int i =0; i < nums.size(); i++)
            for(int j=0; j < i; j++)
                if(nums[i] > nums[j] && ans[i] < ans[j] +1)
                    ans[i] = ans[i] +1; 
        
        return *max_element(ans.begin(), ans.end());
    }
};