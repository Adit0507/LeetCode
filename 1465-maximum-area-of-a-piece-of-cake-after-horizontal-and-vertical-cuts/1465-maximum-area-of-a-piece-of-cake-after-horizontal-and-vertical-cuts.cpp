class Solution {
    const long long MOD = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int a = horizontalCuts[0];
        for(int i=1; i < horizontalCuts.size(); i++)
            a = max(a, horizontalCuts[i] - horizontalCuts[i - 1]);
        
        int b = verticalCuts[0];
        for(int i=1; i < verticalCuts.size(); i++)
            b = max(b, verticalCuts[i] - verticalCuts[i -1]);
        
        return (long long)a * (long long)b % MOD;
    }
};