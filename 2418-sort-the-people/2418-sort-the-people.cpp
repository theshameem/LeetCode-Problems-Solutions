class Solution {
public:
    static bool cmp(const pair<string, int> A, const pair<string, int> B){
        return A.second > B.second;
    }
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> v;
        for(int i = 0; i < names.size(); i++){
            v.push_back({names[i], heights[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        vector<string> ans;
        for(auto i: v){
            ans.push_back(i.first);
        }
        
        return ans;
    }
};