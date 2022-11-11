class Solution {
public:
    void solve(int pos, vector<int> arr, vector<vector<int>>& ans, int target, vector<int> tmp){
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        for(int i = pos; i < arr.size(); i++){
            if(i > pos && arr[i - 1] == arr[i]) continue;
            if(arr[i] > target) break;
            tmp.push_back(arr[i]);
            solve(i + 1, arr, ans, target - arr[i], tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, ans, target, {});
        return ans;
    }
};