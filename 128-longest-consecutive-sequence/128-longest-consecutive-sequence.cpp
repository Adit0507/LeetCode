class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> s;
        for(int num: nums){
            s.insert(num);
        }
        
        int longestStreak = 0;
        
        for(int num: nums){
            if(!s.count(num - 1)){
                int currentNum = num;
                int currentStreak = 1;
                
                while(s.count(currentNum + 1)){
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};