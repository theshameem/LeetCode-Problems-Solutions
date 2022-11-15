class Solution {
public:
    
    vector<vector<int>> allPermutations;
    vector<int> flag;
    
    void generatePermutations(vector<int> nums, vector<int> currPermutation){
        if(currPermutation.size() == nums.size()){
            allPermutations.push_back(currPermutation);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(flag[i] == 1) continue;
            flag[i] = 1;
            currPermutation.push_back(nums[i]);
            generatePermutations(nums, currPermutation);
            flag[i] = 0;
            currPermutation.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        flag.resize(10, 0);
        generatePermutations(nums, {});
        
        return allPermutations;
    }
};