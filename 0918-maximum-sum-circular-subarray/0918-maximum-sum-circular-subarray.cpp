class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total= 0, maxSum= nums[0], currMax= 0, minSum= nums[0], currMin= 0;
        
        for(int i: nums){
            currMax= max(currMax+ i, i);
            maxSum = max(maxSum,currMax);
            currMin =min(currMin +i, i);
            minSum = min(minSum, currMin);
            
            total += i;
        }
        return maxSum > 0 ?  max(maxSum, total - minSum): maxSum;
    }
};