class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map <string, int> m;
        
        for(auto word: words){
            m[word] ++;
        }
        
        vector<int> ans;
        int wordsLen = words.size(), wordLen = words[0].size(), sLen = s.length();
        // strLen is the length of substring, combination of all words
        int strLen = wordsLen* wordLen;
        
        if(strLen > sLen)
            return {};
        
        for(int i =0; i < (sLen - strLen +1); i++){
            int startIdx = -1;
            
            string str = "";
            bool isOk = true;
            
            unordered_map <string, int> temp = m;
            
            for(int j =i; j <= strLen + i; j++){
                // when the string becomes = wordLen
                if(str.length() == wordLen){
                    // Should be presetn in map
                    if(temp[str]> 0){
                        //reduce occurence
                        temp[str] --;
                        // make string empty
                        str = "";
                        
                        startIdx = startIdx == -1? i:startIdx;
                    }else{
                        isOk = false;
                        break;
                    }
                }
                str += s[j];
            }
            
            if(isOk){
                ans.push_back(startIdx);
            }
        }
        
        return ans;
    }
};