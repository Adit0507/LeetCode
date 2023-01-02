class Solution {
public:
    bool detectCapitalUse(string word) {
        int c= 0;
        for(int i= 0; i < word.size(); i++){
            if(isupper(word[i]))
                c++;
        }
        
        if(c== word.size() || (c== 0) ||(c== 1 && isupper(word[0])))
            return true;
        return false;
    }
};