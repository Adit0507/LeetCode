class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n= capacity.size(), ans= 0;
        for(int i= 0; i < n; i++){
            capacity[i] = capacity[i]- rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for(auto x:capacity){
            if(additionalRocks >= x){
                additionalRocks -= x;
                ans ++;
            }
        }
        return ans;
    }
};