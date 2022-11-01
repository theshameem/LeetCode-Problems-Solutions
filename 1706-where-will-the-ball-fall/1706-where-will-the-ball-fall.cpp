class Solution {
public:
    int findBallDropColumn(int i, int j, vector<vector<int>>& grid){
        if(i == grid.size()) return j;
        int nextCol = j + grid[i][j];
        if(nextCol < 0 || nextCol > grid[0].size() - 1 || grid[i][j] != grid[i][nextCol]){
            return -1;
        }
        
        return findBallDropColumn(i + 1, nextCol, grid);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i = 0; i < grid[0].size(); i++){
            ans.push_back(findBallDropColumn(0, i, grid));
        }
        return ans;
    }
};