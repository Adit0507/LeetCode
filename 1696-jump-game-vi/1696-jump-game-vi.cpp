class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> A(n);
        deque<int> q;
        q.push_back(n-1);
        A[n-1] = nums[n -1];
        
        for(int i = n-2; i >= 0; i--){
            if(q.front() -i > k)
                q.pop_front();
           
            A[i] = nums[i] + A[q.front()];
            while(q.size() && A[q.back()] < A[i])
                q.pop_back();
            q.push_back(i);
        } 
        return A[0];
    }
};