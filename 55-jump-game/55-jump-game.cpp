class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        int reach = 0;
        int i = 0;
        for(int i = 0; i <= reach && i < n; i++){
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};