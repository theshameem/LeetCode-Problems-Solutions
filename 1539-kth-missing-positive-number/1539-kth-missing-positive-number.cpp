class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int tmp[5000], cnt = 0, ans = 0;
        for(int i = 1; i < 5000; i++) tmp[i] = 0;
        for(int i = 0; i < arr.size(); i++){
            tmp[arr[i]] = 1;
        }
        
        for(int i = 1; i < 5000; i++){
            if(tmp[i] == 0) ++cnt;
            if(cnt == k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};