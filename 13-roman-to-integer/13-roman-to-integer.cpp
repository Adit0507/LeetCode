class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0, num=0;
        
        for(int i=n; i >= 0; i--){
            
            switch(s[i]){
                    
                case 'I':
                    num = 1;
                    break;
                
                case 'V':
                    num = 5;
                    break;
                    
                case 'X':
                    num = 10;
                    break;
                
                case 'L':
                    num = 50;
                    break;
                    
                case 'C':
                    num = 100;
                    break;
                    
                case 'D':
                    num = 500;
                    break;
                    
                case 'M':
                    num = 1000;
                    break;    
            }
            
            if(4*num < ans)
                ans -=num;
            else
                ans +=num;
        }
        return ans;
    }
};