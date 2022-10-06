class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMap[key].push_back({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        // If key doesnt exist in the string
        if(keyTimeMap.find(key) == keyTimeMap.end())
            return "";
        if(timestamp < keyTimeMap[key][0].first)
            return "";
        
        int l =0, r = keyTimeMap[key].size();
        while(l < r){
            int mid = l + (r-l)/2;
            if(keyTimeMap[key][mid].first <= timestamp)
                l = mid + 1;
            else
                r = mid; 
        }
        if(r == 0)
            return "";
        
        return keyTimeMap[key][r - 1].second;
    }
};  

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */