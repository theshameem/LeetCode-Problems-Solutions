class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> ans = board;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                for(int ii = max(0, i - 1); ii < min(i + 2, n); ii++){
                    for(int jj = max(0, j - 1); jj < min(j + 2, m); jj++){
                        if(board[ii][jj] == 1) ++cnt;
                    }
                }
                
                if(board[i][j] == 0){
                    if(cnt == 3) ans[i][j] = 1;
                } else {
                    --cnt;
                    if(cnt < 2 || cnt > 3) ans[i][j] = 0;
                }
            }
        }
        
        board = ans;
    }
};