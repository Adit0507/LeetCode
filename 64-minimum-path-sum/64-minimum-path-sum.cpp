class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector <int> ans(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            ans[i] = ans[i - 1] + grid[i][0];
        for(int j = 1; j < n; j++){
            ans[0] += grid[0][j];
            for(int i =1; i < m; i++)
                ans[i] = min(ans[i-1], ans[i]) + grid[i][j];
        }
        return ans[m -1];
    }
};