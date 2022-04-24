class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int n = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] < 0){
                    n += grid[0].size() - j;
                    break;
                }
            }
        }
        return n;
    }
};