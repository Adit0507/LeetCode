class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n,0);
        int p= 0, neg = 1;
        
        for(auto i: nums){
            if(i >0){
                ans[p] = i;
                p +=2;
            }else{
                ans[neg] = i;
                neg += 2;
            }
        }
        
        return ans;
    }
};