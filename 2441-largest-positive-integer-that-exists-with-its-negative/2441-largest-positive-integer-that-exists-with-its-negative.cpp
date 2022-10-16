class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mx = 0;
        for(int i: nums){
            if(mp[i * -1] > 0){
                mx = max(mx, abs(i));
            }
            mp[i]++;
        }
        return mx == 0 ? -1 : mx;
    }
};