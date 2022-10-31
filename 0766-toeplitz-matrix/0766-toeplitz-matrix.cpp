class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {        
        for(int i = 0; i < matrix[0].size(); i++){
            int val = matrix[0][i];
            int j = i, k = 0;
            while(k < matrix.size() && j < matrix[0].size()){
                if(val != matrix[k][j]) return false;
                ++k, ++j;
            }
        }

        for(int i = 1; i < matrix.size(); i++){
            int val = matrix[i][0];
            int j = i, k = 0;
            while(k < matrix[0].size() && j < matrix.size()){
                if(val != matrix[j][k]) return false;
                ++k, ++j;
            }
        }
        
        return true;
    }
};