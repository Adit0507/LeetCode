class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), per = 0;
        
        for(int i =0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    per += 4;
                    
                    if(i > 0 && grid[i -1][j] == 1)
                        per -= 2;
                    if(j >0 && grid[i][j -1] == 1)
                        per -= 2;
                }
            }
        }
        return per;
    }
};