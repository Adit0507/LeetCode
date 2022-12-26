class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int i, reach= 0;
        for(int i= 0; i < n && i<= reach; i++){
            reach = max(reach, i+ nums[i]);
        }
        return reach >= n-1;
    }
};