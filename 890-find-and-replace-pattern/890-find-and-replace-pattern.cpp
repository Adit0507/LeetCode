class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int len=pattern.size();
        vector <string> ans;
        
        for(auto word:words){
            if(len !=word.size())
                continue;
            unordered_set<char> uniqueChars_word, uniqueChars_pattern;
            for(auto w:word)
                uniqueChars_word.insert(w);
            
            for(auto p:pattern)
                uniqueChars_pattern.insert(p);
            if(uniqueChars_word.size() != uniqueChars_pattern.size())
                continue;
            
            unordered_map<char, char> map;
            unordered_set<char> used_as_value;
            int i;
            for(i =0; i < len; i++){
                if(map.find(word[i]) != map.end()){
                    if(pattern[i] !=map[word[i]])
                        break;
                } else{
                    if(used_as_value.find(pattern[i]) == used_as_value.end())
                        map[word[i]] = pattern[i];
                    else
                        break;
                }
            }
            if(i ==len)
                ans.push_back(word);
        }
        return ans;
    }
};

















