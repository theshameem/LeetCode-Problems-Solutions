class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int sum = accumulate(nums.begin(), nums.end(), (long long int)0);
        int n = nums.size();
        long long int mx = INT_MAX, ans = n - 1, curSum = 0;

        for(int i = 0; i < n; i++){
            curSum += nums[i];
            long long int leftAvg = (curSum / (i + 1));
            long long int rightAvg = (i == n - 1 ? 0 : (sum - curSum) / (n - (i + 1)));
            
            long long int avg = abs(leftAvg - rightAvg);
            if(avg < mx){
                ans = i;
                mx = avg;
            }
        }
        
        return ans;
    }
};