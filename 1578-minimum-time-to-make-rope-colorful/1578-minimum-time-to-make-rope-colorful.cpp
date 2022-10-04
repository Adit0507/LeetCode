class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       // totalTime: Time needed to make rope colorful
      // currMax: max. time of a balloon needed in the group
        int totalTime = 0, currMax = 0;

        //For each balloon in the array
        for(int i = 0;i < colors.size(); i++){
            // If this balllon is 1st ballon of a new group set the currMax as 0
            if(i > 0 && colors[i] != colors[i -1])
                currMax = 0;
//          Inc. totalTime by smaller one
            // update currMax as the larger one
            totalTime += min(currMax, neededTime[i]);
            currMax = max(currMax, neededTime[i]);
        }
        return totalTime;
    }
};