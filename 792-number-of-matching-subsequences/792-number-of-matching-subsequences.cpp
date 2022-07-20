class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words){
        vector<string> m[128];
        for(auto str: words)
            m[str[0]].push_back(str);
        
        int ans = 0;
        unordered_set<string> subS;
        for(int i = 0; i < s.size(); i++){
            auto v = m[s[i]];
            m[s[i]].clear();
            for(auto word: v){
                if(word.size() ==1)
                    ans++;
                else
                    m[word[1]].push_back(word.substr(1));
            }
        }
        return ans;
    }
};