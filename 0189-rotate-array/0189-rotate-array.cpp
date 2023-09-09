class Solution {
public:
    void reverse(vector<int>&nums, int i, int j){
        int l =i;
        int r = j;
        while(l < r){
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            l++; r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k = k% n;
        if(k <0){
            k += n;
        }
        reverse(nums, 0, n - k- 1);
        reverse(nums, n - k,n -1);
        reverse(nums, 0, n -1);
    }
};