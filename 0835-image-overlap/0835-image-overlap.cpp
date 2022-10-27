class Solution {
public:
    int countOverlap(int x, int y, vector<vector<int>>& A, vector<vector<int>>& B){
        int leftCount = 0, rightCount = 0;
        int rRow = 0;
        
        for(int i = y; i < A.size(); i++){
            int rCol = 0;
            for(int j = x; j < A.size(); j++){
                if(A[i][j] == 1 && A[i][j] == B[rRow][rCol]) ++leftCount;
                if(A[i][rCol] == 1 && A[i][rCol] == B[rRow][j]) ++rightCount;
                rCol++;
            }
            rRow++;
        }
                                                            
        return max(leftCount, rightCount);
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        
        for(int i = 0; i < img1.size(); i++){
            for(int j = 0; j < img1.size(); j++){
                ans = max(ans, countOverlap(j, i, img1, img2));
                ans = max(ans, countOverlap(j, i, img2, img1));
            }
        }
        
        return ans;
    }
};