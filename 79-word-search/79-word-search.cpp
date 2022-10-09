class Solution {
public:
    bool ans = false;
    int vis[20][20];
    void floodFill(int i, int j, int idx, int n, int m, vector<vector<char>>& board, string word){
        if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] == 1 || board[i][j] != word[idx] || ans == true) return;
        vis[i][j] = 1;
        if(idx + 1 == word.size()){
            ans = true;
            return;
        }
        // for(int x = 0; x <= idx; x++) cout << word[x];
        // cout << endl;
        floodFill(i + 1, j, idx + 1, n, m, board, word);
        floodFill(i, j + 1, idx + 1, n, m, board, word);
        floodFill(i - 1, j, idx + 1, n, m, board, word);
        floodFill(i, j - 1, idx + 1, n, m, board, word);
        
        vis[i][j] = 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(word[0] == board[i][j]){
                    memset(vis, 0, sizeof vis);
                    floodFill(i, j, 0, board.size(), board[i].size(), board, word);
                    if(ans) return ans;
                }
            }
        }
        return ans;
    }
};