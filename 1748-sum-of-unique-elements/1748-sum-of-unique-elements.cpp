class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum= 0;
        map<int, int> mp;
        
        for(auto i: nums)
            mp[i]++;
        
        for(auto m: mp){
            if(m.second == 1)
                sum += m.first;
        }
        return sum;
    }
};