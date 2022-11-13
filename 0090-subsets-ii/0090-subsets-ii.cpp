class Solution {
public:
    set<vector<int>> v;
    void solve(int pos, vector<int> nums, vector<int> cur){
        if(pos == nums.size()){
            v.insert(cur);
            return;
        }    
        
        cur.push_back(nums[pos]);
        solve(pos + 1, nums, cur);
        cur.pop_back();
        solve(pos + 1, nums, cur);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0, nums, {});
        for(auto it = v.begin(); it != v.end(); ++it){
            ans.push_back(*it);
            // for(auto i: *it) cout << i << " ";
            // cout << endl;
        }
        return ans;
    }
};