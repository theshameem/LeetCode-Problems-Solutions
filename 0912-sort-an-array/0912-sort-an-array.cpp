class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        
        map<int, int> mp;
        for(int i: nums) mp[i]++;
        
        for(auto i: mp){
            while(i.second > 0){
                ans.push_back(i.first);
                i.second--;
            }
        }
        
        return ans;
    }
};