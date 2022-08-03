class MyCalendar {
public:
    vector<pair<int, int>> a;
    int n;
    MyCalendar() {
        n = a.size();
    }
    
    bool book(int start, int end) {
        bool ans = true;
        
        for(int i = 0; i < n; i++){
            if(a[i].first < end && start < a[i].second){
                ans = false;
                break;
            }
        }
        
        if(ans){
            a.push_back({start, end});
            n++;
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */