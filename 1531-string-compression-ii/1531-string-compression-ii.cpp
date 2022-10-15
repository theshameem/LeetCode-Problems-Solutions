int dp[105][27][105][105];
class Solution {
public:
    string str;
    
    int solve(int pos, int prev, int len, int k){
        if(k < 0) return INT_MAX;
        if(pos >= str.size()) return 0;
        
        int val = dp[pos][prev][len][k];
        if(val != -1) return val;
        
        int curDelete = solve(pos + 1, prev, len, k - 1);
        int keep = 0;
        if(str[pos] - 'a' == prev){
            if(len == 1 || len == 9 || len == 99) ++keep;
            keep += solve(pos + 1, prev, len + 1, k);
        } else {
            keep = 1 + solve(pos + 1, str[pos] - 'a', 1, k);
        }
        return dp[pos][prev][len][k] = min(curDelete, keep);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        memset(dp, -1, sizeof dp);
        return solve(0, 26, 0, k);
    }
};