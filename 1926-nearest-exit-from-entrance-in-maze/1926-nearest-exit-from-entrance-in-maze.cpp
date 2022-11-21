class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> Q;
        Q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int ans = 1, row = maze.size(), col = maze[0].size();
        vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        
        while(Q.size()){
            int sz = Q.size();
            
            for(int k = 0; k < sz; k++){
                auto [i, j] = Q.front();
                Q.pop();
                
                for(int l = 0; l < 4; l++){
                    int x = i + dirs[l][0];
                    int y = j + dirs[l][1];
                    if(x < 0 || y < 0 || x >= row || y >= col || maze[x][y] == '+') continue;
                    if(x == 0 || y == 0 || x == row - 1 || y == col - 1) return ans;
                    maze[x][y] = '+';
                    Q.push({x, y});
                }
            }
            ++ans;
        }
        
        return -1;
    }
};