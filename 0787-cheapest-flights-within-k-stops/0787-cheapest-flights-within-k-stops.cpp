class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &e: flights)
            adj[e[0]].push_back({e[1], e[2]});
        
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src]= 0;
        
        for(int i =0; i <= k; i++){
            vector<int> temp(dist);
            
            for(auto &flight: flights){
                if(dist[flight[0]] != numeric_limits<int>::max()){
                    temp[flight[1]]= min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = temp;
        }
        
        return dist[dst]== numeric_limits<int>::max() ? -1: dist[dst];
    }
};