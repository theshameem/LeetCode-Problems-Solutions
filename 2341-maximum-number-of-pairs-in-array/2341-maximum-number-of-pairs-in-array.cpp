class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> mp;
        for(int i: nums) mp[i]++;
        int cntPair = 0, remain = 0;
        for(auto i: mp){
            cntPair += (i.second / 2);
            remain += (i.second % 2);
        }
        return {cntPair, remain};
    }
};