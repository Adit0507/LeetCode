class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, bool> vis;
        
        vector<string> wordList;
        stringstream st(s);
         
        string word;
        int c = 0;
        
        while(st >>word){
            c++;
            wordList.push_back(word);
        }
        if(pattern.size()!= c){
            return false;
        }else{
            for(int i = 0; i < pattern.size(); i++){
                char c= pattern[i];
                
                if(mp[c]== "" && vis[wordList[i]]== true)
                    return false;
                else if(mp[c]== ""){
                    mp[c]= wordList[i];
                    vis[wordList[i]] = true;
                }
                else{
                    if(mp[c] !=wordList[i])
                        return false;
                }
            }
        }
        return true;
    }
};