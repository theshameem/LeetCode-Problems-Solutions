class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> countOne;
        map<int, int> countTwo;
        
        for(int i: nums1) countOne[i]++;
        for(int i: nums2) countTwo[i]++;
        
        vector<int> ans;
        for(auto x: countOne){
            if(countTwo.count(x.first)){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};