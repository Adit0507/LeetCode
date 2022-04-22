class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        
        if(nums[j] >= nums[i])
            return nums[i];
        
        while(i<j){
            int k = i + (j-i)/2;
            if(nums[k] >= nums[0])
                i = k + 1;
            else
                j = k;
        }
        return nums[i];
    }
};