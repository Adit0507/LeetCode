class Solution {
public:
    void solve(int c, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftRow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n){
        if(c== n){
            ans.push_back(board);
            return;
        }
        
        for(int r= 0; r <n; r++){
            if(leftRow[r]== 0&& lowerDiagonal[r +c]== 0&& upperDiagonal[n-1 + c- r]== 0){
                board[r][c] = 'Q';
                leftRow[r]= 1;
                lowerDiagonal[r+c] = 1;
                upperDiagonal[n -1+c -r]= 1;
                solve(c + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[r][c] = '.';
                leftRow[r] = 0;
                lowerDiagonal[r +c] = 0;
                upperDiagonal[n - 1 +c-r] =0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i= 0; i < n; i++)
            board[i] =s;
        
        vector<int> leftRow(n, 0), upperDiagonal(2*n -1, 0), lowerDiagonal(2*n -1, 0);
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};