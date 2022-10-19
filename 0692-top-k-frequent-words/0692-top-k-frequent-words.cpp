class Solution {
public:
    
    static bool cmp(const pair<string, int> A, const pair<string, int> B){
        if(A.second == B.second) return A.first < B.first;
        return A.second > B.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        
        for(auto i: words) mp[i]++;
        
        vector<pair<string, int> > v;
        vector<string> ans;
        
        for(auto i: mp){
            v.push_back({i.first, i.second});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        for(auto i: v){
            ans.push_back(i.first);
            k--;
            if(k <= 0) break;
        }
        
        return ans;
    }
};