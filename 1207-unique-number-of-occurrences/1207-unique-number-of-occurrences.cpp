class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for(int &i: arr) mp[i]++;
        
        map<int, int> ans;
        for(auto &i: mp) ans[i.second]++;
        return mp.size() == ans.size();
    }
};