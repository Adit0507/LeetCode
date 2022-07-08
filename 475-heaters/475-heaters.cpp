class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int ans = 0, i =0;
        
        for(const int house: houses){
            while(i + 1 < heaters.size() && house - heaters[i] > heaters[i + 1] - house)
                i++;
            ans = max(ans, abs(heaters[i] - house));
        }
        return ans;
    }
};