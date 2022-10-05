class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0, x = 1;
        while(n > x){
            n -= x;
            x++, ++ans;
        }
        if(n >= x) ++ans;
        return ans;
    }
};