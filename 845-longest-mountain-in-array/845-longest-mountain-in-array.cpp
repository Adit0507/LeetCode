class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        
        if(n < 3)
            return 0;
        
        int ans = 0, l= 0, r = 0;
        // l = increasing and r = decreasing in this case
        
        for(int i = 1; i < n; i++){
            
            if(arr[i] > arr[i - 1]) // Increasing count
            {
                if(r) {
                    l = 0; 
                    r = 0;
                }
                l += (1 + (l==0));
            }
            else if (arr[i] < arr[i - 1] && l)  // r = decreasing count
                r += 1;
            else {      // same numbers
                l = 0;
                r = 0;
            }
            ans = max((l + r) * (l && r), ans);   // maximize the ans
        }
        return ans;
    }
};