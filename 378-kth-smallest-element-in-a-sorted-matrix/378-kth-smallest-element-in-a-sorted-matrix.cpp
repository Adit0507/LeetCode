class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        
        while(l <= r){
            int mid = l + (r - l)/2;
            int count =0;
            for(int i=0; i < n; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(count < k){
                l = mid + 1;
            } else{
                r = mid-1;
            }
        }
        return l;
    }
};