class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> m;
        int n = nums.size();
        
        int sum = 0, c = 0;
        m[0]++;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int temp = sum - k;
            if(m[temp] != 0)
                c += m[temp];
            m[sum]++;
        }
        return c;
    }
};