class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>ans1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int left=j+1;
                int right=n-1;
                while(left<right)
                {
                    int sum1=nums[i]+nums[j];
                    int sum2=target-(nums[left]+nums[right]);
                    if(sum2<sum1)
                    {
                        right--;
                    }
                    else if(sum1==sum2)
                    {
                        vector<int>v{nums[i],nums[j],nums[left],nums[right]};
                        ans1.insert(v);
                        left++;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
        vector<vector<int>>ans(ans1.begin(),ans1.end());
        return ans;
        
    }
};