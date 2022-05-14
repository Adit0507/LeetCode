class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> result;
        
        int row = matrix.size();
        
        if(row == 0){
            return result;
        }
        
        int col = matrix[0].size();
        
        if(row == 0 && col == 0){
            return result;
        }
        
        if(row == 1 && col == 1){
            result.push_back(matrix[0][0]);
            return result;
        }
        
        int l = 0, r = col;
        int top = 0, bottom = row;
        
        
        while(top < bottom && left < right){
            if(top < bottom){
                for(int i = l; i < r;i++){
                    result.push_back(matrix[top][i]);
                }
                top ++;
            }
            
            if(l < r){
                for(int i = top; i < bottom; i++){
                    result.push_back(matrix[i][r - 1]);
                }
                r --;
            }
            
            if( top < bottom ) {
                for( int i = r - 1; i >= l ; i-- ) {
                    result.push_back(matrix[bottom-1][i]);
                }
                bottom--;
            }
            
            if(l < r){
                for( int i = bottom - 1 ; i >= top ; i-- ) {
                    result.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return result;        
    }
};