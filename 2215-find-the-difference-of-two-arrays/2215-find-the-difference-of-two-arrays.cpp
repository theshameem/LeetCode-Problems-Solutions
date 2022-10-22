class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> countOne;
        map<int, int> countTwo;
        
        for(int i: nums1) countOne[i]++;
        for(int i: nums2) countTwo[i]++;
        
        vector<vector<int>> ans;
        ans.push_back({});
        ans.push_back({});
        
        for(auto x: countOne){
            if(countTwo.count(x.first) == 0){
                ans[0].push_back(x.first);
            }
        }
        
        for(auto x: countTwo){
            if(countOne.count(x.first) == 0){
                ans[1].push_back(x.first);
            }
        }
        
        return ans;
    }
};