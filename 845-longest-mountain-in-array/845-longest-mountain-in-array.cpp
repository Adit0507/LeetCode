class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        
        if(n < 3)
            return 0;
        
        int ans = 0, l= 0, r = 0;
        
        for(int i = 1; i < n; i++){
            
            if(arr[i] > arr[i - 1])
            {
                if(r) {
                    l = 0; 
                    r = 0;
                }
                l += (1 + (l==0));
            }
            else if (arr[i] < arr[i - 1] && l)
                r += 1;
            else {
                l = 0;
                r = 0;
            }
            ans = max((l + r) * (l && r), ans);
        }
        return ans;
    }
};