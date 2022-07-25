class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            int n = nums.size();
            vector<int> ans;
            if(nums.empty())
                return vector<int> {-1, -1};

            int l =0, r = nums.size() -1;
            while(l +1 < r){
                int mid = l + (r - l)/2;
                if(nums[mid] < target)
                    l = mid;
                else
                    r = mid;
            }
        
        if(nums[l] == target)
            ans.push_back(l);
        else if(nums[r] == target)
            ans.push_back(r);
        else
            return vector<int> {-1, -1};
        
        l =0, r=nums.size()-1;
        while(l +1 < r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= target)
                l = mid;
            else
                r = mid;
        }
        if(nums[r] == target)
            ans.push_back(r);
        else if(nums[l] == target)
            ans.push_back(l);
        
        return ans;
    }
};













