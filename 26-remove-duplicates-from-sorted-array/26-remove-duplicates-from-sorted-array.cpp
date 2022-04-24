class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = (int)nums.size();
        int i = 0;
        while(i < nums.size()){
            int val = nums[i];
            ++i;
            while(i < nums.size() && nums[i] == val){
                nums[i] = 100000;
                ++i;
                --ans;
            }
        }
        
        for(i = 0; i < nums.size(); i++){
            if(nums[i] == 100000){
                nums.erase(nums.begin() + i);
                --i;
            }
        }
        return ans;
    }
};