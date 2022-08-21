class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // grid.size() -> Row Size
        // grid[0].szie() => Col Size
        int i = 0;    
        int j = grid[0].size() -1; 
        int s = grid.size();
        int c = 0;
        
        while(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()){
            if(grid[i][j] < 0){
                c = c + s;
                j--;
            }
            else{
                i ++;
                s--;
            }
        }
        return c;
    }
};