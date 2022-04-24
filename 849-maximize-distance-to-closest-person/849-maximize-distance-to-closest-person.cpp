class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0, ans = 0, cnt = 0, first = 0;
        while(i < seats.size()){
            if(seats[i] == 1){
                if(first == 0){
                    ans = max(ans, cnt);
                    first = 1;
                } else {
                    ans = max(ans, (cnt / 2) + (cnt % 2));
                }
                cnt = 0;
                ++i;
            } else {
                while(i < seats.size() && seats[i] == 0){
                   ++i, ++cnt;
                }
            }
        }
        if(cnt > 0) ans = max(ans, cnt);
        
        return ans;
    }
};