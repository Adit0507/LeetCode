class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int CurrSum = 0, TotalSum = INT_MIN;
        
        for(int i = 0; i < n; i++){
            CurrSum += nums[i];
            TotalSum = max(CurrSum, TotalSum);
            
            CurrSum = max(0, CurrSum);
        }
        return TotalSum;
    }
};