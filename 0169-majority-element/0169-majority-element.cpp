class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        int mz = sz / 2, mx = 0, ans = 0;;
        map<int, int> mp;
        for(int i: nums){
            mp[i]++;
            if(mp[i] > mx){
                ans = i;
                mx = mp[i];
            }
        }
        return ans;
    }
};