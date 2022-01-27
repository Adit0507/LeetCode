class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
                for(int i=0; i < nums.size(); i++){
                    if(i > 0 && nums[i] == nums[i-1])
                        continue;
                    int tar = -nums[i];
                    int j = i+1, k = n-1;
                    while(j < k){
                            if(nums[j] + nums[k] > tar) k--;
                        else if(nums[j] + nums[k] < tar) j++;
                        else{
                            ans.push_back({nums[i],nums[j],nums[k]});
                            while(j < k && nums[j] == nums[j+1]) j++;
                            while(j < k && nums[k] == nums[k-1]) k--;
                            j++;
                            k--;
                        }
                    }
                }
                return ans;  
    }
};