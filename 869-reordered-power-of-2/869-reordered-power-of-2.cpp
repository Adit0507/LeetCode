class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long c = count(n);
        for(int i = 0; i < 32; i++)
            if(count(1 << i) == c)
                return true;
        return false;
    }
    int count(int n){
        int ans = 0;
        for(;n; n /= 10)
            ans += pow(10, n%10);
        return ans;
    }
};