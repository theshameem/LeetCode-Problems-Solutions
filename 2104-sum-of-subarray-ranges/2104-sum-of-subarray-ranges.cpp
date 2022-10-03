class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        for(int i = 0; i < nums.size(); i++){
            int mn = INT_MAX, mx = INT_MIN;
            for(int j = i; j < nums.size(); j++){
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                res += (mx - mn);
            }
            
        }
        return res;
    }
};