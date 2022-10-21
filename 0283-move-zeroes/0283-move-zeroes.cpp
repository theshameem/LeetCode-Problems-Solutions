class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = -1, otherPointer = 0;;
        while(otherPointer < nums.size()){
            if(nums[otherPointer] == 0 && zeroPointer == -1){
                zeroPointer = otherPointer;
                ++otherPointer;
                continue;
            }
            
            if(nums[otherPointer] != 0 && zeroPointer != -1){
                swap(nums[otherPointer], nums[zeroPointer]);
                ++otherPointer, ++zeroPointer;
            } else {
                otherPointer++;
            }
        }
    }
};