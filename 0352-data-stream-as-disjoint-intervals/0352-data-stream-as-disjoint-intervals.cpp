class SummaryRanges {
public:
    set<int> nums;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        nums.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int s= -1, e= -1;
        
        for(auto &ele : nums){
            if(s == -1){
                s = ele;
                e = ele;
            }
            else if(ele == e +1)
                e = ele;
            else{
                ans.push_back({s, e});
                s = ele;
                e = ele;
            }
        }
        if(s != -1)
            ans.push_back({s, e});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */