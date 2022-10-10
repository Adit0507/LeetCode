class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n= palindrome.length();
        
        int i =0;
        while(i < n/2){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
            i++;
        }
        palindrome[n -1]= 'b';
        return n < 2 ? "": palindrome;
    }
};