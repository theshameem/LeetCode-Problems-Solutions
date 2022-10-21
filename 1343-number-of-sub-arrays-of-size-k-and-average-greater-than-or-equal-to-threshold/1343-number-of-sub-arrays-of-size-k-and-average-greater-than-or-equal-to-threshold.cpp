class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, j = 0, ans = 0, need = k * threshold;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            
            if(i + 1 >= k){
                if(sum >= need) ++ans;
                sum -= arr[j];
                j++;
            } 
        }
        return ans;
    }
};