class Solution {
public:
    int dp[105], n;
    int solve(vector<int>& nums, int pos, int last){
        if(pos >= last) return 0;
        if(dp[pos] != -1) return dp[pos];
        
        int sum1 = 0, sum2 = 0;
        sum1 = nums[pos] + solve(nums, pos + 2, last);
        sum2 = solve(nums, pos + 1, last);
        
        return dp[pos] = max(sum1, sum2);
    }
    
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        n = nums.size();
        if(n == 1) return nums[0];
        int ans = solve(nums, 0, n - 1);
        memset(dp, -1, sizeof dp);
        ans = max(ans, solve(nums, 1, n));
        
        return ans;
    }
};