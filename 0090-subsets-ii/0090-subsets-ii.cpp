class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int pos,vector<int> nums, vector<int> v){
        ans.push_back(v);
        for(int i = pos; i < nums.size(); i++){
            if(i != pos && nums[i] == nums[i - 1]) continue;
            v.push_back(nums[i]);
            solve(i + 1, nums, v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums, {});
        return ans;
    }
};
