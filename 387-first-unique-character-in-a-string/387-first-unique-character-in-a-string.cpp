class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++){
            if(freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};