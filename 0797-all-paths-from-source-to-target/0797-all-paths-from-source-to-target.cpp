class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int u, vector<vector<int>>& adj, vector<int>&v){
        if(u== adj.size()-1)
            ans.push_back(v);
        
        for(int i =0; i < adj[u].size(); i++){
            v.push_back(adj[u][i]);
            dfs(adj[u][i], adj,v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        ans.clear();
        v.push_back(0);
        dfs(0, graph, v);
        
        return ans;
    }
};