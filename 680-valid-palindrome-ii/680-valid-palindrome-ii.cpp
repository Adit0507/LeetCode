class Solution {
public:
    bool isPalindromeRange(string s, int i, int j){
        while (i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            int j = s.size() - 1 - i;
            if(s[i] != s[j]){
                return isPalindromeRange(s, i + 1, j) || isPalindromeRange(s, i, j - 1);
            }
        }
        return true;
    }
};