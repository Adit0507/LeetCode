class Solution {
public:
    bool isAlphaNum(char c)
    {
    if( (48<=c && c<=57) || (65<=c && c<=90) || (97<=c && c<=122)) 
        return true;
    return false;
    }

char lowerCase(char c)
    {
    if(65<=c && c<=90)
        return c+32;
    else 
        return c;
    }    
    bool isPalindrome(string s) {
        int l =0, r = s.size() -1;
        while(l <= r){
            while(l < r && !isAlphaNum (s[l]))
                l++;
            while(l < r && !isAlphaNum(s[r]))
                r--;
            
            if(lowerCase(s[l]) != lowerCase(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};