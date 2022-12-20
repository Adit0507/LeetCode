class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int>&vis, int curr){
        vis[curr] = 1;
        for(int i =0; i < rooms[curr].size(); i++){
            if(!vis[rooms[curr][i]]){
                dfs(rooms, vis, rooms[curr][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<int> vis(n, 0);
        
        dfs(rooms, vis, 0);
        for(int i =0; i < n; i++){
            if(vis[i] ==0)
                return false;
        }
        return true;
    }
};