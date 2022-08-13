class Solution {
public:
    void recur(int index, vector <int> &nums, vector<vector<int>> &ans){
        // When the index reaches the end
        if(index == nums.size()){   
            ans.push_back(nums);
            return;
        }    
        
        for(int i= index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            // After swapping we call the recur for the next index
            recur(index +1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(0, nums, ans);
        return ans;
    }
};