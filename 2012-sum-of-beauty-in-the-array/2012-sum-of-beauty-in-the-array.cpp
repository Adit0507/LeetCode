class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n= nums.size();
        vector<int> minOfRight(n, 0);
        minOfRight[n-1] = nums[n -1];
        
        for(int i= n -2; i >= 2; i--){
            minOfRight[i] = min(minOfRight[i + 1], nums[i]);
        }
        
        int maxOnLeft= nums[0];
        int ans= 0;
        for(int i= 1; i < n -1; i++){
            if(nums[i] > maxOnLeft && nums[i] <minOfRight[i + 1])
                ans += 2;
            else if(nums[i] > nums[i -1] && nums[i] < nums[i + 1])
                ans += 1;
            maxOnLeft= max(nums[i], maxOnLeft);
        }
        return ans;
    }
};