class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int ans= 0;
        // To identify the last color
        int prev = 0;
        
        for(int curr =1; curr < n; curr++){
            // if curr and prev are same update and delete min oness
            if(colors[prev] == colors[curr]){
                if(neededTime[prev] < neededTime[curr]){
                    ans += neededTime[prev];
                    prev = curr;        
                }else{
                    ans += neededTime[curr];
                }
            } else{
                prev = curr;
            }
        }
        return ans;
    }
};