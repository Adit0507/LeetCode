class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0)
            return 0;
        
        int i = 0, j = 0, sum = 0, minimum = INT_MAX;
    
        while(j < n){
            sum += nums[j++];
            
            while(sum >= target){
                minimum = min(minimum, j - i);
                sum -= nums[i++];
            }
        }
        return minimum == INT_MAX ? 0: minimum;
    }
};