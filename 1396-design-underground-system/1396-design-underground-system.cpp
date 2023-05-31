class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> m1, m2;
    unordered_map<string, vector<pair<int, int>>> m;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m1[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        m2[id]= {stationName, t};
        string ans = "";
        ans += m1[id].first;
        ans += "->";
        ans += m2[id].first;
        m[ans].push_back({m1[id].second, m2[id].second});
    }
    
    double getAverageTime(string startStation, string endStation) {
        string tempo = startStation + "->" + endStation;
        auto x= m[tempo];
        double a= 0.0;
        int n= x.size();
        for(auto y:x){
            a += (double)(y.second- y.first);
        }
        
        return (double)(a/n);
    }
};
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */