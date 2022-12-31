class Solution {
public:
    int ans;
    void findAll(vector<vector<int>> &grid, vector<vector<bool>>&vis, int i, int j, int c){
        if(i >= grid.size() || i <0 || j>= grid[0].size() ||j < 0 ||vis[i][j] || grid[i][j] == -1)
            return;
        
        if(grid[i][j] ==2 && c == 0)
            ans ++;
        
        vis[i][j] =1;
        c--;
        
        findAll(grid, vis, i +1, j, c);
        findAll(grid, vis, i -1, j, c);
        findAll(grid, vis, i, j+1, c);
        findAll(grid, vis, i, j -1, c);
        
        vis[i][j] = 0;
        c++;    
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
        int m, n;
        int c = 0;
        ans = 0;
        
        for(int i= 0; i < grid.size(); i++){
            for(int j= 0; j <grid[0].size(); j++){
                if(grid[i][j]== 0)
                    c++;
                if(grid[i][j] ==1){
                    m= i;
                    n= j;
                    c++;
                }
            }
        }
        findAll(grid, vis, m, n,c);
        return ans;
    }
};