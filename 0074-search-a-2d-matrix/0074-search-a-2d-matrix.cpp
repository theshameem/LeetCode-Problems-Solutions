class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int first = 0, last = (n * m) - 1;
        
        while(first <= last){
            int mid = (first + last) / 2;
            int i = mid / m, j = mid % m;
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) last = mid - 1;
            else first = mid + 1;
            // cout << matrix[i][j] << endl;
        }
        return false;
    }
};