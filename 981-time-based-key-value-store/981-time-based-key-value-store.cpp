class TimeMap {
public:
    map<string,map<int,stack<string>>> hash;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key][timestamp].push(value);
    }
    
    string get(string key, int timestamp) {
        auto itr = hash[key].lower_bound(timestamp+1);
        if(itr != hash[key].begin()) itr--;
        
        if(itr == hash[key].end() or (itr->second).size() == 0 or itr->first > timestamp) return "";
        return (itr->second).top();
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */