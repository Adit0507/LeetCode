class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n -1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target <= nums[mid]){
                    r = mid - 1;
                } else{
                    l = mid + 1;
                }
            }
            
            else {
                if(target <= nums[r] && target >= nums[mid]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};