class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size(), ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < len - 2; i++){
            int j = i + 1, k = len - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;
                if(abs(sum - target) < abs(ans - target)){
                    ans = sum;
                }
                if(sum > target) --k;
                else ++j;
            }
            
        }
        return ans;
    }
};
