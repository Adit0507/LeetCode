class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int, int> freq, found;
        for(int &i: nums) 
            freq[i]++;
        for(int &i: nums){
            if(!freq[i])
                continue;
            freq[i]--;
            if(found[i - 1] > 0){
                found[i -1]--;
                found[i]++;
            }
            else if(freq[i+ 1] && freq[i + 2]){
                freq[i + 1]--;
                freq[i + 2] --;
                found[i +2]++;
            }
            else 
                return false;  
        }
        return true;
    }
};