class Solution {
public:
    bool isVowel(char c){
        if(c =='a' || c== 'A' || c=='e' ||c=='E' ||c=='i' || c=='I' || c=='o' || c=='O' ||c=='u' || c=='U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int c1 = 0, c2=0;
        
        for(int i=0; i < (s.length())/2; i++){
            if(isVowel(s[i]))
                c1++;
        }
        for(int i= (s.length())/2; i < (s.length()); i++){
            if(isVowel(s[i]))
                c2++;
        }
        return c1 == c2;
    }
};