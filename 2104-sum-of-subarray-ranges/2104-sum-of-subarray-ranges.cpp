class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector <int> l_greater(n, -1), r_greater(n, n);
        vector <int> l_smaller(n, -1), r_smaller(n,n);
        stack <int> s1, s2, s3, s4;
        
        for(int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] < nums[i]){
                r_greater[s1.top()] = i;
                s1.pop();
            }
            s1.push (i);
        }
        
        for(int i=n -1; i >= 0; i--){
            while(!s2.empty() && nums[s2.top()] <= nums[i]){
                l_greater[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        
        for(int i = 0; i < n; i++){
            while(!s3.empty() && nums[s3.top()] > nums[i]){
                r_smaller[s3.top()] = i;
                s3.pop();
            }
            s3.push(i);
        }
        
        for(int i = n-1; i >= 0; i--){
            while(!s4.empty() && nums[s4.top()] >= nums[i]){
                l_smaller[s4.top()] = i;
                s4.pop();
            }
            s4.push(i);
        }
        
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long maxi = (r_greater[i] - i) * (i - l_greater[i]);
            long long mini = (r_smaller[i] - i) * (i - l_smaller[i]);
            ans += (maxi*nums[i]);
            ans -= (mini*nums[i]);
        }        
        return ans;
    }
};
















