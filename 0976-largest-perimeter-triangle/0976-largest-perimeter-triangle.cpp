class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        // Sort in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=1; i <n; i++){
            int a = nums[i -1], b= nums[i], c= nums[i +1];
            if(a < b + c)
                return a + b + c;
        }
        return 0;
    }
};