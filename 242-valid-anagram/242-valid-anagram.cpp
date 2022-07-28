class Solution {
public:
    bool isAnagram(string s, string t) {
        // Sorting makes it easier
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s.size() != t.size())
            return false;
        
        for(int i=0; i < s.size(); i++){
            if(s[i] !=t[i])
                return false;
        }
        return true;
    }
};