class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        vector<long long> prefix(n);
        
        for(int i=0;i < n; i++){
            totalSum += nums[i];
            prefix[i] = totalSum;
        }
        
        int minVal= INT_MAX;
        int ans = 0;
        
        for(int i=0; i < n; i++){
            int div = i+ 1;
             long long l = prefix[i]/div;
             long long r = 0;
            
            if(n - div)
                r = (totalSum - prefix[i])/(n -div);
            
            long long temp = abs(l -r);
            
            if(temp < minVal){
                minVal = temp;
                ans = i;
            }
        }
        return ans;
    }
};