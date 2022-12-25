class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        for(auto q: queries){
            int c=0;
            for(auto num: nums){
                if(q >=num){
                    q -=num;
                    c ++;
                }
                else
                    break;
            }
            ans.push_back(c);
        }
        return ans;
    }
};