class Solution {
    private:
        vector<vector<int>> allPermutations;
        vector<int> takenValue;
public:
    void generatePermutations(vector<int> nums, vector<int> currPermutation){
        if(currPermutation.size() == nums.size()){
            allPermutations.push_back(currPermutation);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(takenValue[i] == 1) continue;
            takenValue[i] = 1;
            currPermutation.push_back(nums[i]);
            generatePermutations(nums, currPermutation);
            takenValue[i] = 0;
            currPermutation.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        takenValue.resize(10, 0);
        generatePermutations(nums, {});
        
        return allPermutations;
    }
};