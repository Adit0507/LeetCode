class Solution {
public:
    void func(int ind, int sum, int n, vector<vector<int>> &ans, vector<int> &ans2, int k){
        
        // Base Case
        if(sum == n && k==0){
            ans.push_back(ans2);
            return;
        }
        if(sum > n)
            return;
        
        for(int i=ind; i<= 9; i++){
            if(i > n)
                break;
        
        ans2.push_back(i);
        func(i +1, sum + i, n, ans, ans2, k -1);    
         ans2.pop_back();   
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans2;
        vector<vector<int>> ans;
        func(1, 0, n, ans, ans2, k);
        return ans;
    }
};