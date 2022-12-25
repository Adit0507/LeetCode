class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        for(int i= 1; i < nums.size(); i++)
            nums[i] += nums[i -1];
        
        for(auto q: queries){
            int i= upper_bound(nums.begin(), nums.end(), q)- nums.begin();
            ans.push_back(i);
        }
        return ans;
    }
};