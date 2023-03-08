class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        
        while(left < right){
            int mid = (left + right) / 2;
            int total = 0;
            
            for(int i: piles){
                total += (i + mid - 1) / mid;
            }
            
            if(total > h) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
};

