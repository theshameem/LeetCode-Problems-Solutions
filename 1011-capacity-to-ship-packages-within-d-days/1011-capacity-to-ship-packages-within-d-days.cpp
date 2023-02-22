class Solution {
public:
    bool coverPossible(vector<int>& weights, int cap, int days){
        int daysNeed= 1, curLoad = 0;
        for(int i: weights){
            curLoad += i;
            if(curLoad > cap){
                daysNeed++;
                curLoad = i;
            }
        }
        
        return daysNeed <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0, mx = 0;
        
        for(int i:  weights){
            total += i;
            mx = max(mx, i);
        }
        
        int left = mx, right = total;
        
        while(left < right){
            int mid = (left + right) / 2;
            if(coverPossible(weights, mid, days)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};