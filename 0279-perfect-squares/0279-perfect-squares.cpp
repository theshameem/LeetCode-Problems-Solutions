class Solution {
public:
    int numSquares(int n) {
        int vis[n + 5];
        memset(vis, 0, sizeof vis);
        queue<pair<int, int>> Q;
        Q.push({n, 0});
        
        while(Q.size()){
            auto [val, step] = Q.front();
            Q.pop();
            
            if(vis[val]) continue;
            vis[val] = 1;
            
            int sq = sqrt(val);
            for(int i = sq; i > 0; i--){
                int remain = val - (i * i);
                if(remain == 0) return ++step;
                Q.push({remain, step + 1});
            }
        }
        return 0;
    }
};