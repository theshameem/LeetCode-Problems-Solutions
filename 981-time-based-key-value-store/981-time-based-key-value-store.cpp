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
        string ans = "";
        
        auto it = mp[key].upper_bound(timestamp);
        if(it == mp[key].begin()) return "";
        
        it = prev(it);
        if(it != mp[key].end()) return it->second;
        
        return "";
        

        // for(auto i: mp[key]){
        //     if(i.first == timestamp){
        //         ans = i.second;
        //         break;
        //     } else if(i.first > timestamp) {
        //         if(!ans.size()) ans = "";
        //         break;
        //     } else {
        //         ans = i.second;
        //     }
        // }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */