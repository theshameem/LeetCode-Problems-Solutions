class Solution {
public:
    int n;
    vector<int> job;
    int dp[305][15];
    
    int solve(int pos, int d){
        if(d == 1){
            return *max_element(job.begin() + pos, job.end());
        }   

        if(dp[pos][d] != -1) return dp[pos][d];
        
        int res = INT_MAX, currD = INT_MIN;
        
        for(int i = pos; i <= n - d; i++){
            currD = max(currD, job[i]);
            res = min(res, currD + solve(i + 1, d - 1));
        }
        return dp[pos][d] = res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        job = jobDifficulty;
        n = jobDifficulty.size();
        
        if(n < d) return -1;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0, d);
    }
};