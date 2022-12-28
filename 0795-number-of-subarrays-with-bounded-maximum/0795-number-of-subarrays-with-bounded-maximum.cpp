class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans= 0, l= -1, r= -1, n= nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > right)
                l= i;
            if(nums[i] >= left)
                r =i;
            ans += r -l;
        }
        return ans;
    }
};