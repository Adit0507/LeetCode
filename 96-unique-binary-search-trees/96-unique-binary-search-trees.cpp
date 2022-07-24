class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n + 1);
        ans[0] = ans[1] =1;
        
        for(int i=2; i <= n; i++)
            for(int j=1; j <= i; j++)
                ans[i] += ans[j - 1]*ans[i-j];
        return ans[n];
    }
};