class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack <int> s;
        vector <int> ans(n);
        
        
        for (int i=0; i < 2*n; i++){
            while (!s.empty() && nums[i%n] > nums[s.top()]){
                // Using i%n because we need to keep i in a range
                // Will get an error if we dont do tht
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            if (i < n){
                s.push(i%n);
            }
        }
        while (!s.empty()){
            ans[s.top()] = -1;
            s.pop();
        }
        return ans;
    }
};