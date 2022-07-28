class MyHashSet {
public:
    int bucketSize =123;
    vector<int>bucket[123];
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = key%bucketSize;
        if(!contains(key))
            bucket[index].push_back(key);   
    }
    
    void remove(int key) {
        int index = key%bucketSize;
        for(int i=0; i < bucket[index].size(); i++){
            if(bucket[index][i] == key){
                bucket[index].erase(bucket[index].begin() + i);
                break;
            }
        }
    }
    
    bool contains(int key) {
        int index = key%bucketSize;
        for(auto i: bucket[index]){
            if(i ==key)
                return true;
        }        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */