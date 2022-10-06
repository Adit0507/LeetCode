class TimeMap {
public:
    unordered_map<string, unordered_map<int, string>> keyTimeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!keyTimeMap.count(key)) 
            return "";
        
        for(int curTime = timestamp; curTime >=1; curTime--){
            if(keyTimeMap[key].count(curTime)){
                return keyTimeMap[key][curTime];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */