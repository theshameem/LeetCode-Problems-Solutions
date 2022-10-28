class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        
        for(int i = 0; i < strs.size(); i++){
            string sortStr = strs[i];
            sort(sortStr.begin(), sortStr.end());
            
            if(mp[sortStr].size()){
                mp[sortStr].push_back(strs[i]);
            } else {
                mp[sortStr] = {strs[i]};
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto i: mp){
            vector<string> curStr;
            for(int j = 0; j < i.second.size(); j++){
                curStr.push_back(i.second[j]);
            }
            ans.push_back(curStr);
        }
        return ans;
    }
};