class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        
        int Max_Dist= m + n + 1;
        
        for(int i= 0; i < m; i++){
            for(int j= 0; j < n; j++){
                if(grid[i][j])
                    grid[i][j]= 0;
                else{
                    grid[i][j]= Max_Dist;
                    grid[i][j]= min(grid[i][j], min(i > 0 ? grid[i -1][j] + 1: Max_Dist, j> 0 ? grid[i][j -1]+ 1: Max_Dist));
                }
            }
        }
        
        int ans= INT_MIN;
        for(int i= m - 1; i >= 0; i--){
            for(int j= n -1; j >= 0; j--){
                grid[i][j]= min(grid[i][j], min(i <m-1 ? grid[i + 1][j] + 1: Max_Dist, j < n -1 ? grid[i][j + 1] + 1: Max_Dist));
                ans = max(ans, grid[i][j]);
            }
        }
        return ans == 0 || ans == Max_Dist ? -1 : ans;
    }
};










































