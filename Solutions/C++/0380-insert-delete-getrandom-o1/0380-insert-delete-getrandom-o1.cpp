class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    RandomizedSet() {
        v = vector<int>();
        mp = unordered_map<int,int>();
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return 0;
        mp[val] = v.size();
        v.push_back(val);
        return 1;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return 0;
        int index = mp[val];
        mp.erase(val);
        if (index != v.size() - 1){
            swap(v[index], v[v.size()-1]);
            mp[v[index]] = index;
        }
        v.pop_back();
        return 1;
    }
    
    int getRandom() {
        int size = v.size();
        return v[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */