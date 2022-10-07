class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int left = 0, right = 0, ans = 0, prod = 1;
        while(right < nums.size()){
            prod *= nums[right];
            while(prod >= k) prod /= nums[left++];
            ans += (right - left + 1);
            ++right;
        }
        return ans;
    }
};