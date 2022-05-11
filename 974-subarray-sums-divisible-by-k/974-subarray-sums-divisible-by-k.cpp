class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        int sum = 0;
        int c = 0;
        m[0]++;
        for(int i = 0; i < n; i++){
            sum = (sum + nums[i]) % k;
            sum = (sum + k)%k;
            
            int temp = sum;
            if(m[temp] != 0) c += m[temp];
            m[sum]++;
        }
        return c;
    }
};