class Solution {
private:
    int robber(vector<int>&nums, int l, int r){
        int prev= 0, curr= 0;
        
        for(int i= l; i <= r; i++){
            int temp= max(prev +nums[i], curr);
            prev= curr;
            curr = temp;
        }
        return curr;
    }    
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n <2)
            return n ? nums[0]: 0;
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
        
    }
};