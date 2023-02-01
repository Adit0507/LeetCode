class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n= str1.length(), m= str2.length();
        
        if(n < m) return gcdOfStrings(str2, str1);
        
        if(str2.empty()) return str1;
        if(str1.substr(0, m) !=str2) return "";
        return gcdOfStrings(str1.substr(m), str2);
    }
};