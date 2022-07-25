class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        
        for(int i = 0; i < nums.size() -1; i++){
            if(nums[i] < nums[i +1])
                dec = false;
            if(nums[i] > nums[i + 1])
                inc = false;
            if(inc == false && dec == false)
                return false;
        }
        return true;
    }
};