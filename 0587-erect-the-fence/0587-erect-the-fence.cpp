class Solution {
public:
    static bool cmp(const vector<int>& A, const vector<int>& B){
        return A[0] < B[0] || (A[0] == B[0] && A[1] < B[1]);    
    }
    
    static int orientation(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), cmp);

        int n = trees.size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            while(ans.size() > 1 && orientation(ans[ans.size() - 2], ans.back(), trees[i]) < 0){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        
        if(ans.size() == n) return ans;
        
        for(int i = n - 2; i >= 0; i--){
            while(ans.size() > 1 && orientation(ans[ans.size() - 2], ans.back(), trees[i]) < 0){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }
        ans.pop_back();
        
        return ans;
    }
};