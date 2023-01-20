class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int>& seq, vector<int>& nums, int pos){
        if(seq.size() >1)
            ans.push_back(seq);
        unordered_set<int> hash;
        
        for(int i= pos; i < nums.size(); i++){
            if((seq.empty() ||nums[i] >=seq.back()) && hash.find(nums[i]) ==hash.end()){
                seq.push_back(nums[i]);
                dfs(ans, seq, nums, i + 1);
                seq.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seq;
        
        dfs(ans, seq, nums, 0);
        return ans;
    }
};