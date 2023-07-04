class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto i: mp){
            if(i.second == 1) ans = i.first;
        }
        
        return ans;
    }
};