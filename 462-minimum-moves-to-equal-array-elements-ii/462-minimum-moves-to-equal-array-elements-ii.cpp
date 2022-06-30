class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = n %2 == 0 ? (nums[n/2 - 1] +  nums[n/2])/2 : nums[n/2];
        
        int moves = 0;
        for(int num: nums)
            moves += abs(num - median);
        return moves;
    }
};