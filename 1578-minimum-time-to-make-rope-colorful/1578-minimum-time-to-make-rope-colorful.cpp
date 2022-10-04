class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int i =0, j = 0;
        
        while(i < neededTime.size() && j < neededTime.size()){
            int curTotal = 0, curMax = 0;
            
            while(j < neededTime.size() && colors[i] == colors[j]){
                curTotal += neededTime[j];
                curMax = max(curMax, neededTime[j]);
                j++;
            }
            totalTime += curTotal - curMax;
            i = j;
        }
        return totalTime;
    }
};