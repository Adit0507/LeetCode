class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int g = numsDivide[0];
        
        for(int a:numsDivide)
         g = gcd(g, a);
        
        for(int i = 0; i < nums.size(); i++)
            if(g % nums[i] == 0)
                return i;
        return -1;
    }
};