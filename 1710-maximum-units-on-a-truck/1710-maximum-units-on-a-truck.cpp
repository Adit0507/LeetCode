class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), [](const auto&a, const auto&b){
            return a[1] > b[1];
        });
        
        int res = 0;
        for(const auto&boxType : boxTypes){
            if(truckSize > boxType[0]){
                truckSize -= boxType[0];
                res += boxType[0]*boxType[1];
            }else {
                res += truckSize * boxType[1];
                break;
            }
        }
        return res;
    }
};