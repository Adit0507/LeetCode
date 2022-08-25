class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        
        // Inserting every character  of magazine with its frequency in map
        for(auto a: magazine){
            m[a]++;
        }
        
        //Traverse ransomNote, every for its character its frequency in map, must not be 0 or less
        for(auto a: ransomNote){
            if(m[a] > 0){
                m[a]--;
            }else
                return false;
        }
        return true;
    }
};