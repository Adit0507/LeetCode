class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(n,1);
        if(m ==1 || n ==1)
            return 1;
        for(int i= 1; i <= m -1; i++)
            for(int j=1; j <=n -1; j++){
                ans[j] = ans[j] + ans[j -1];
            }
        return ans[n -1];
    }
};