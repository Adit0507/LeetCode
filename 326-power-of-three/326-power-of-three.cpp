class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n > 0){
            while(n%3 == 0){
                n /= 3;
            }
            if(n ==1) return true;
        }
        return false;
    }
};