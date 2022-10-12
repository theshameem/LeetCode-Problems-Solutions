class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = INT_MAX;
        int first = 0, last = nums.size() - 1;
        
        while(first <= last){
            int mid = (first + last) / 2;
            mn = min(mn, nums[mid]);
            
            if(nums[first] > nums[mid] && nums[last] > nums[mid]){
                if(nums[first] > nums[last]){
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            } else if(nums[first] < nums[last]){
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return mn;
    }
};