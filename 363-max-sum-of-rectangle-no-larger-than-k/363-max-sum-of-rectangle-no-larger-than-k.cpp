class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        int ans = INT_MIN;
        
        for(int l=0; l < col; l++){
            vector <int> sums(row, 0);
            for(int r= l; r <col; r++){
                for(int i=0; i < row; i++){
                    sums[i] += matrix[i][r];
                }
                
                set <int> acc;
                acc.insert(0);
                int currSum = 0, currMax = INT_MIN;
                for(int sum: sums){
                    currSum += sum;
                    set<int> ::iterator it = acc.lower_bound(currSum - k);
                    if(it != acc.end())
                        currMax = max(currMax, currSum - *it);
                        acc.insert(currSum);
                }
                ans = max(ans, currMax);
            }
        }
        return ans;
    }
};