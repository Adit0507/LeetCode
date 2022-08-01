class MyHashMap {
public:
    // hasmap is used to store key and value
     int bucketSize = 10007;
    vector< list<pair<int, int>> > bucket;
    MyHashMap() {
        bucket.resize(bucketSize);
    }
    void put(int key, int value){
        auto &list = bucket[key % bucketSize];
        for(auto &val: list){
            if(val.first == key){
                val.second = value;
                return;
            }
        }
        list.push_back({key, value});
    }
    int get(int key){
        auto &list = bucket[key % bucketSize];
        for(auto &val: list){
            if(val.first == key)
                return val.second;
        }
        return -1;
    }
    void remove(int key) {
        auto &list = bucket[key % bucketSize];
        for(auto &val: list){
            if(val.first == key){
                list.remove(val);
                return ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */