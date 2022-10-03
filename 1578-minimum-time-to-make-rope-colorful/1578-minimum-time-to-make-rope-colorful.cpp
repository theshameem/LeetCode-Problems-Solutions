class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, cnt = 1, mx = neededTime[0], sum = neededTime[0];
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] == colors[i - 1]){
                sum += neededTime[i];
                mx = max(mx, neededTime[i]);
                ++cnt;
            } else {
                if(cnt > 1) ans += (sum - mx);
                mx = neededTime[i];
                sum = neededTime[i];
                cnt = 1;
            }
        }
        if(cnt > 1) ans += (sum - mx);
        return ans;
    }
};