class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 1, cand = nums[0];
        
        for(int i = 0; i < n; i++){
            if(cand == nums[i]){
                c ++;
            }
            else{
                c--;
            }
            if(c == 0){
                cand = nums[i];
                c = 1;
            }
        }
        
        c = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == cand){
                c ++;
            }
            if(c > n/2)
                break;
        }
        return cand;
    }
};