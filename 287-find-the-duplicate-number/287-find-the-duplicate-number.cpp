class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 0; i < nums.size(); i++){
            int val = abs(nums[i]);
            if(nums[val] < 0) return val;
            else nums[val] *= -1;
        }
        return ans;
    }
};