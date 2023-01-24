class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n= board.size();
        
        vector<pair<int, int>>cells(n*n + 1);
        int label= 1;
        vector<int> cols(n);
        // iota stores in an increasing sequence
        iota(cols.begin(), cols.end(), 0);
        for(int i = n -1; i >= 0; i--){
            for(int col: cols)
                cells[label++] = {i, col};                
            reverse(cols.begin(), cols.end());
        }
        
        vector<int> dist(n*n +1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int next = cur + 1; next <=min(cur +6, n*n); next++){
                auto [row, col]= cells[next];
                int dest = board[row][col] != -1 ? board[row][col]: next;
                
                if(dist[dest]== -1){
                    dist[dest] = dist[cur] + 1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
    }
};































