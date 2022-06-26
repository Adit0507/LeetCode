class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        int minLength = INT_MIN;
        int l = 0, r = n -1;
        
        while (l < r && arr[l + 1] >= arr[l]){
            l ++;
        }
        
        if(l == n -1)
            return 0;
        
        while (r > l && arr[r - 1] <= arr[r]){
            r --;
        }
        
        minLength = min(n - l -1, r);
        
        int j =r;
        for(int i=0; i < l + 1; i++){
            if(arr[i] <= arr[j]){
                minLength = min(minLength, j - i -1);
            }
            else if(j < n -1){
                j++;
            }
            else 
                break;
        } 
        
        return minLength;
    }
};










