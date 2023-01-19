class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int c = 0;
        unordered_map <int, bool>m;
        
        for(int i=0; i < nums.size(); i++)
            m[nums[i]]= true;
        
        for(int i=0; i < nums.size(); i++){
            if(m[nums[i] - diff] && m[nums[i] + diff])
                c++;
        }
        return c;
    }
};