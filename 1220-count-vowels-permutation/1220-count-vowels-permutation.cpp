class Solution {
public:
    int countVowelPermutation(int n) {
        long long a=1, b=1, c=1, d=1,e =1;
        long sum = 0;
        int mod=1e9 +7;
        
        for(int i = 0; i < n; i++){
            sum = (a +b+c+d+e)%mod;
            
            long long arr[5] = {a,b,c,d,e};
            a = (arr[1] + arr[2] + arr[4])%mod;
            b = (arr[0] + arr[2]) %mod;
            c = (arr[1] + arr[3]) %mod;
            d = (arr[2])%mod;
            e = (arr[2] + arr[3]) %mod;
        }
        return sum%mod;
    }
};