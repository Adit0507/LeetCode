class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int h = n -1;
        int i = 0;
        
        while(i <= h) {
            if(nums[i] == 1)
                i++;
            else if (nums[i] == 0){
                nums[i++] = nums[l];
                nums[l++] = 0;
            }
            else {
                nums[i] = nums[h];
                nums[h--] = 2;
            }
        }
    }
};