class Solution {
public:
    int sz, reqTarget;
    vector<int> can;
    vector<vector<int>> ans;
    map<vector<int>, int> mp;
    
    void solve(int pos, vector<int> v){
        if(pos == sz) return;
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum > reqTarget) return;

        if(sum == reqTarget){
            sort(v.begin(), v.end());
            if(mp[v] > 0) return;
            ans.push_back(v);
            mp[v]++;
            return;
        }
        
        v.push_back(can[pos]);
        solve(pos, v);
        solve(pos + 1, v);
        v.pop_back();
        solve(pos + 1, v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        can = candidates;
        sz = can.size();
        reqTarget = target;
        vector<int> tmp;
        solve(0, tmp);
        
        return ans;
    }
};