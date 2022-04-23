class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        
        if(n ==0)
            return 0;
        
        while(l < r){
           int mid = l + (r-l)/2;
            
            if(n - mid == citations[mid])
                return citations[mid];
            else if (n-mid <= citations[mid])
                r = mid;
            else
                l = mid + 1;
        }
        return min(n-l,citations[l]);
    }
};