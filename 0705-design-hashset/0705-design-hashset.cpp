class MyHashSet {
public:
    vector<bool> h;
    MyHashSet() {
        h.resize(1e6 + 1);
    }
    
    void add(int key) {
        h[key] = true;
    }
    
    void remove(int key) {
        h[key]= false;
    }
    
    bool contains(int key) {
        return h[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */