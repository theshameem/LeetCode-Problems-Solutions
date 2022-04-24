class Solution {
public:
    int maxPower(string s) {
        int ans = 0, i = 0, cnt = 0;
        while(i < s.size()){
            cnt = 0;
            char ch = s[i];
            while(i < s.size() && s[i] == ch){
                ++cnt, ++i;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};