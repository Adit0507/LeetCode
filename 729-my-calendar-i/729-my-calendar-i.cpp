class MyCalendar {
public:
    map<int, int> books;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = books.lower_bound(start);
        if(next != books.end() && next->first < end)
            return false;
        if(next != books.begin() && start < (--next) ->second)
            return false;
        
        books[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */