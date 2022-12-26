class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int ans= 1;
        sort(coins.begin(), coins.end());
        
        for(auto c:coins){
            if(c> ans) break;
            ans += c;
        }
        return ans;
    }
};