class Solution {
    long long mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> stack;

        vector<int> rSmaller(n, n);
        for(int i = 0; i < n ; i ++){
            while(!stack.empty() && arr[stack.back()] >= arr[i]){
                rSmaller[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
//        Solution::print_vec(rSmaller);

        stack.clear();
        vector<int> lSmaller(n, -1);
        for(int i = n - 1; i >= 0; i --){
            while(!stack.empty() && arr[stack.back()] > arr[i]){
                lSmaller[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
//        Solution::print_vec(lSmaller);

        long long res = 0;
        for(int i = 0; i < n; i ++){
            res += (long long)(rSmaller[i] - i) * (long long)(i - lSmaller[i]) % mod * (long long)arr[i] % mod;
            res %= mod;
        }

        return res;
    }
};










