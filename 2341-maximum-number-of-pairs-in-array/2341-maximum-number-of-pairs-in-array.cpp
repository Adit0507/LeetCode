class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        int pairs = 0, others= 0;
        vector<int> ans(101, 0);
        
        for(int i = 0; i < n; i++){
            ans[nums[i]]++;
        }
        for(int i = 0; i < 101; i++){
            if(ans[i] & 1){
                others ++;
                pairs += (ans[i] -1)/2;
            }else {
                pairs += ans[i]/2;
            }
        }
        return {pairs, others};
    }
};