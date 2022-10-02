class Solution {
public:
    #define MOD 1000000007
    
    vector<vector<int>> dp;
    
    int solve(int n, int target, int k){
        if(target < 0 || n < 0) return 0;
        if(target == 0 && n == 0) return 1;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int ans = 0;
        for(int i = 1; i <= k; i++){
            ans += solve(n - 1, target - i, k) % MOD;
            ans %= MOD;
        }
        return dp[n][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n + 1, vector<int>(target + 2, -1));
        return solve(n, target, k);
    }
};