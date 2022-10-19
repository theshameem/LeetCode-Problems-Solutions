class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> ans = board;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                if(j + 1 < m){
                    if(board[i][j + 1] == 1) ++cnt;
                }
                if(j - 1 >= 0){
                    if(board[i][j - 1] == 1) ++cnt;
                }
                
                if(i + 1 < n){
                    if(board[i + 1][j] == 1) ++cnt;
                    if(j + 1 < m){
                        if(board[i + 1][j + 1] == 1) ++cnt;
                    }
                    if(j - 1 >= 0){
                        if(board[i + 1][j - 1] == 1) ++cnt;
                    }
                }
                
                if(i - 1 >= 0){
                    if(board[i - 1][j] == 1) ++cnt;
                    if(j + 1 < m){
                        if(board[i - 1][j + 1] == 1) ++cnt;
                    }
                    if(j - 1 >= 0){
                        if(board[i - 1][j - 1] == 1) ++cnt;
                    }
                }
                
                if(board[i][j] == 0){
                    if(cnt == 3) ans[i][j] = 1;
                } else {
                    if(cnt < 2 || cnt > 3) ans[i][j] = 0;
                }
            }
        }
        
        board = ans;
    }
};