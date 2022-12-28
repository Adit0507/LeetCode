class Solution {
public:
    int halveArray(vector<int>& nums) {
        double s= accumulate(nums.begin(), nums.end(), 0.0),k = 0, i=0;
        priority_queue<double>pq(nums.begin(), nums.end());
    
        while(s- k> s/2){
            double x= pq.top();
            pq.pop();
            k +=x/2;
            pq.push(x/2);   
            i++;
        }
        return i;
    }
};