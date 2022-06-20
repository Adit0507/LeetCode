class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int r = nums.size() - k;
        int x1 = r;
        
        if (k > nums.size())
        {
            r = nums.size() - k%nums.size();
            x1 = r;
        }
        
        vector <int> V;
        
        if (nums.size() == 1 || k == 0 || k == nums.size())
        {
            r = 0;
            V.push_back (nums[r]);
        }
        else {
            V.push_back(nums[r]);
            
            if (r < nums.size() - 1){
                    r ++;
            }
            else {
                r = 0;
            }
            
            while (r != x1 && r < nums.size())
            {
                V.push_back(nums[r]);
                
                if (r < (nums.size() -1)){
                    r++;
                }
                else {
                    r = 0;
                }
            }
            
            if(k != 0 && k!= nums.size())
            {
                nums.swap(V);
            }
        }
    }
};