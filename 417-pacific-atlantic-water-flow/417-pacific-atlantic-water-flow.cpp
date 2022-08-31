class Solution {
public:
    int rows, cols;
    
    void waterFlowAtlantic(vector<vector<int>> &matrix, vector<vector<bool>>&atlantic, int prev, int i, int j){
        if(i < 0 || i >= rows || j >=cols || j < 0 || matrix[i][j] < prev || atlantic[i][j])
            return;
        
        atlantic[i][j] = true;
        
        waterFlowAtlantic(matrix, atlantic, matrix[i][j], i, j+1);
        waterFlowAtlantic(matrix, atlantic, matrix[i][j], i +1, j);
        waterFlowAtlantic(matrix, atlantic, matrix[i][j], i, j -1);
        waterFlowAtlantic(matrix, atlantic, matrix[i][j], i -1, j);
    }
    
    void waterFlowPacific(vector<vector<int>> &matrix, vector<vector<bool>>&pacific, int prev, int i, int j){
        if(i < 0 || i >= rows || j >=cols || j < 0 || matrix[i][j] < prev || pacific[i][j])
            return;
        
        pacific[i][j] = true;
        
        waterFlowPacific(matrix, pacific, matrix[i][j], i, j+1);
        waterFlowPacific(matrix, pacific, matrix[i][j], i +1, j);
        waterFlowPacific(matrix, pacific, matrix[i][j], i, j -1);
        waterFlowPacific(matrix, pacific, matrix[i][j], i -1, j);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        rows = matrix.size(), cols = matrix[0].size();
        vector<vector<bool>>atlantic(rows, vector<bool>(cols, false));
        vector<vector<bool>>pacific(rows, vector<bool>(cols, false));
        
        for(int i = 0; i < rows; ++i){
            waterFlowPacific(matrix, pacific, -1, i, 0);
        }
        
        for(int i = 0; i < cols; i++){
            waterFlowPacific(matrix, pacific, -1, 0, i);
        }
        
        for(int i =0; i < rows; i++){
            waterFlowAtlantic(matrix, atlantic, -1, i, cols -1);
        }
        
        for(int i =0; i < cols; i++){
            waterFlowAtlantic(matrix, atlantic, -1, rows-1, i);
        }
        
        vector<vector<int>> ans;
        for(int i =0; i< rows; i++){
            for(int j = 0; j < cols; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};