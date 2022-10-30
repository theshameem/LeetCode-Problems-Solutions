class Solution {
public:
    int solve(vector<vector<int>>& grid, int k){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>> Q;
        
        Q.push({0, 0, 0, k});
        while(Q.size()){
            auto cur = Q.front();
            int i = cur[0], j = cur[1];
            Q.pop();
            
            if(i < 0 || i >= n || j < 0 || j >= m) continue;
            
            if(i == n - 1 && j == m - 1) return cur[2];
            
            if(grid[i][j] == 1){
                if(cur[3] > 0)  cur[3]--;
                else continue;
            }
            
            if(vis[i][j] != -1 && vis[i][j] >= cur[3]) continue;
            vis[i][j] = cur[3];
            
            Q.push({i + 1, j, cur[2] + 1, cur[3]});
            Q.push({i - 1, j, cur[2] + 1, cur[3]});
            Q.push({i, j + 1, cur[2] + 1, cur[3]});
            Q.push({i, j - 1, cur[2] + 1, cur[3]});
        }
        
        return -1;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        return solve(grid, k);
    }
};