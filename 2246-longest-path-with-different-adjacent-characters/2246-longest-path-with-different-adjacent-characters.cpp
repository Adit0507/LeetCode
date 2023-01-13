class Solution {
public:
    int dfs(vector<vector<int>>& children, string& s, int& res, int i){
        int b1= 0, b2= 0;
        for(int &j: children[i]){
            int cur = dfs(children, s, res, j);
            if(s[i] ==s[j])
                continue;
            if(cur> b2) b2 = cur;
            if(b2 > b1) swap(b1, b2);
        }
        res = max(res, b1 +b2 +1);
        return b1 +1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n= s.size(), res = 0;
        vector<vector<int>> children(n, vector<int>());
        
        for(int i=1; i < n; i++)
            children[parent[i]].push_back(i);
        
        dfs(children, s, res, 0);
        return res;
    }
};













