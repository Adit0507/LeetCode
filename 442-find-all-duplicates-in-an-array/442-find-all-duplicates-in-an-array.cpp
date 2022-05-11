class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> res;
        
        for(int n: nums){   //Iterating through nums
            n = abs(n);
            if(nums[n-1] > 0)
                nums[n-1] *= -1;
            else res.push_back(n);  
        }
        return res;    
    }
};