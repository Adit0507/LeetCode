class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int, int> mp;
        for(auto i:arr) // Stores the frequency
            mp[i]++;
        // Checks the count and insert in unordered set        
        unordered_set<int> set;
        for(auto i:mp){
            int freq = i.second;
            set.insert(freq);
        }
        
        return set.size()== mp.size();
    }
};