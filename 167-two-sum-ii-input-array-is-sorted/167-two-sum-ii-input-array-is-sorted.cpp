class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res;
        int n = numbers.size();    
        
        int l = 0, r = n - 1;
        
        while(l <= r){
            int sum = numbers[l] + numbers[r];
            
            if(sum > target){
                r --;
            } else if(sum < target){
                l++;
            }
            else {
                return vector <int> {l + 1, r + 1};
            }
        }
        return vector <int> {-1,-1};
    }
};