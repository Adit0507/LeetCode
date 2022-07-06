class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int num = 0, ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                num ++;
            else{
                ans = max(ans, num);    
                num = 0;
            }
        }
        return max(ans, num);
    }
};