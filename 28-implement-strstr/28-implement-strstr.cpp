class Solution {
public:
    int strStr(string haystack, string needle) {
       if(needle.size() == 0){
            return 0;
        }

        if (haystack.size() < needle.size())
            return -1;
        
        int i = 0, j = 0;
        int index;
        
        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                index = i;
                
                while(haystack[i] == needle[j] && j < needle.size()){
                    i ++;
                    j ++;
                }
                
                if(j == needle.size()){
                    return index;
                } 
                else{
                    j = 0;
                    i = index + 1;
                }
            } else{
                i++;
            }
        }
            
        return -1;
    }
};