class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int, int> m;
    int mx = 0;
    
    int book(int start, int end) {
        m[start] ++;
        m[end]--;
        
        int c= 0;
        for(auto[key, value]: m){
            c += value;
            mx =max(mx, c);
        }
        return mx;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */