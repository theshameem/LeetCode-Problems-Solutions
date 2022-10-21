class Solution {
public:
    vector<vector<int>> ans;
    vector<int> num;
    int n;
    
    void solve(int pos, vector<int> v){
        if(pos == n){
            ans.push_back(v);
            return;
        }    
        solve(pos + 1, v);
        v.push_back(num[pos]);
        solve(pos + 1, v);
        v.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        num = nums;
        solve(0, {});
        return ans;
    }
};