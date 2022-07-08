class Solution {
public:
    int arrangeCoins(int n) {
        long l =0, h = n;
        while(l <= h){
            long mid = l + (h-l)/2;
            if((mid + 1)*mid/2 > n){
                h = mid -1;
            } else {
                l = mid + 1;
            }
        }
        return l-1;
    }
};