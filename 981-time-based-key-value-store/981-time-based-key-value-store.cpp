class TimeMap {
public:
    unordered_map<string, map<int, string> > mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        
        for(int curTime = timestamp; curTime >= 1; curTime--){
            if(mp[key].count(curTime)){
                return mp[key][curTime];
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