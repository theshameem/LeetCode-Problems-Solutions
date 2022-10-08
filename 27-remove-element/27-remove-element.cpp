class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] != val){
                nums[i++] = nums[k];
            }
        }
        return i;
    }
};