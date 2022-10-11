class Trie {
public:
    string word;
    bool isEnd = false;
    Trie* children[26] = {NULL};
};

class Solution {
private:
    Trie* root = NULL;
    
    void addWord(string &s){
        Trie* tmp = root;
        for(auto &i: s){
            int index = i - 'a';
            if(tmp->children[index] == NULL){
                tmp->children[index] = new Trie;
            }
            tmp = tmp->children[index];
        }
        tmp->word = s;
        tmp->isEnd = true;
    }
    
    void floodFill(int i, int j, vector<vector<char>>& board, vector<string>& ans, Trie* tmp){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*' || !(tmp->children[board[i][j] - 'a'])) return;
        
        tmp = tmp->children[board[i][j] - 'a'];
        if(tmp->isEnd){
            ans.push_back(tmp->word);
            tmp->isEnd = false;
        }
        
        char prevLetter = board[i][j];
        board[i][j] = '*';
        
        floodFill(i + 1, j, board, ans, tmp);
        floodFill(i - 1, j, board, ans, tmp);
        floodFill(i, j + 1, board, ans, tmp);
        floodFill(i, j - 1, board, ans, tmp);
        
        board[i][j] = prevLetter;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Trie;
        for(auto word: words){
            addWord(word);
        }
        vector<string> ans;
        Trie* tmp = root;
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                floodFill(i, j, board, ans, tmp);
            }
        }
        return ans;
    }
};