class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = 0, otherPointer = 0;;
        while(otherPointer < nums.size()){
            if(nums[otherPointer] != 0){
                swap(nums[otherPointer], nums[zeroPointer]);
                ++otherPointer, ++zeroPointer;
            } else {
                otherPointer++;
            }
        }
    }
};