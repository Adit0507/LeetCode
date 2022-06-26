class TimeMap {
public:
    unordered_map<string, vector<pair <int, string>>> m;
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ret="";
        
        vector<pair<int, string >>&v = m[key];
        int l = 0; 
        int h = v.size() - 1;
        
        while(l <= h){
            int mid = l + (h-l)/2;
            if(v[mid].first <= timestamp){
                ret = v[mid].second;
                l = mid + 1;
            }else{
                h = mid -1;
            }
        }
        return ret;
    }
};











/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */