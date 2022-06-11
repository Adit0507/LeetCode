class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set <vector<int>> ans1;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-3; i++){
            for(int j = i+1; j < n -2; j++){
                int l = j + 1;
                int r = n - 1;
                
                while(l < r){
                    int s1 = nums[i] + nums[j];
                    int s2 = target - (nums[l] + nums[r]);
                    
                    if(s2 < s1){
                        r --;
                    }
                    
                    else if(s1 == s2)
                    {
                        vector<int>v{nums[i],nums[j],nums[l],nums[r]};
                        ans1.insert(v);
                        l++;
                    }
                    else {
                        l ++;
                    }
                }
            }
        }
        vector<vector<int>> ans(ans1.begin(), ans1.end());
        return ans;
    }
};