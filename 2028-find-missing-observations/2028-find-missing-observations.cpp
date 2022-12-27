class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int s= rolls.size();
        int curSum= accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = mean*(s + n)- curSum;
        
        if(missingSum < n || missingSum > 6*n)
            return {};
        int part= missingSum/ n, rem= missingSum%n;
        vector<int> ans(n, part);
        
        for(int i= 0; i < rem; i++)
            ans[i]++;
        return ans;
    }
};