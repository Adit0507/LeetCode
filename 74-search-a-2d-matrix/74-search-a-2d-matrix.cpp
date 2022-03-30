class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        
        int l = 0, r = (m*n) - 1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if(matrix[mid/m][mid%m] ==target) {
                return true;
            }
            if(matrix[mid/m][mid%m] >target) {
                r = mid -1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};