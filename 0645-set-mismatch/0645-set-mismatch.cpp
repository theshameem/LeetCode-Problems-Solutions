class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(len + 5, 0);
        
        for(int i: nums) count[i]++;
        
        int duplicate = -1, missing = -1;
        
        for(int i = 1; i <= len; i++){
            if(count[i] == 1) continue;
            if(count[i] == 2) duplicate = i;
            else missing = i;
        }
        
        return vector<int> {duplicate, missing};
    }
};