class NumArray {
public:
    vector<int>& sum;
    NumArray(vector<int>& nums): sum(nums) {
        for(int i= 1; i < sum.size(); i++)
            sum[i] += sum[i -1];
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return sum[right];
        
        return sum[right]- sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */