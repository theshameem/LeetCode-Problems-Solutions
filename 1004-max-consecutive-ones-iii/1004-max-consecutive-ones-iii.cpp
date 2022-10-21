class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, cntK = 0;
        for(int i = 0, j = 0; j < nums.size(); ){
            if(nums[j] == 0){
                if(cntK < k){
                    ++cntK;
                    ++j;
                } else {
                    if(nums[i] == 0) cntK--;
                    ++i;
                }
            } else {
                ++j;
            }
             ans = max(ans, j - i);
        }
        return ans;
    }
};