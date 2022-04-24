class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int arr[nums.size() + 1];
        //memset(arr, 1, sizeof(arr));
        for(int i = 0; i < nums.size(); i++) arr[i] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    if(arr[j] <= arr[i] + 1){
                        arr[j] = arr[i] + 1;
                    }
                }
            }
        }
        
        int ans = 1;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, arr[i]);
        }
        if(! nums.size()) ans = 0;
        return ans;
    }
};