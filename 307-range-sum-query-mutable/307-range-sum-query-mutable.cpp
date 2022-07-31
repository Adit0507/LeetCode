class NumArray {
    int n;
    vector <int> seg;
    
    int build(const vector<int> &nums, int l, int r, int node){
        int mid;
        int leftSum, rightSum;
        
        if(l ==r)
            return seg[node] = nums[l];
        mid = (l + r)/2;
        leftSum  =build(nums, l, mid, 2*node +1);
        rightSum = build(nums, mid +1, r, 2*node + 2);
        
        return seg[node] = leftSum + rightSum;
    }
    
    int sumRange(int l, int r, int ss, int se, int node){
        int mid;
        int leftSum, rightSum;
        
        if(r < ss || l > se)
            return 0;
        if(l <= ss && se <= r)
            return seg[node];
        
        mid = (ss + se)/2;
        leftSum = sumRange(l, r, ss, mid, 2*node + 1);
        rightSum = sumRange(l, r, mid +1, se, 2*node +2);
        
        return leftSum + rightSum;
    }
    
    int update(int index, int newVal, int ss, int se, int node){
        int leftSum, rightSum;
        int mid;
        
        if(index < ss || index > se)
            return seg[node];
        if(ss == se)
            return seg[node] = newVal;
        mid = (ss + se)/2;
        leftSum = update(index, newVal, ss, mid, 2*node + 1);
        rightSum = update(index, newVal, mid+ 1, se, 2*node + 2);
        
        return seg[node] = leftSum + rightSum;
    }
    
public:
    NumArray(vector<int>& nums) {
        n =nums.size();
        seg.resize(4*n);
        build(nums, 0, n -1, 0);
    }
    
    void update(int index, int val) {
        update(index, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n -1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */