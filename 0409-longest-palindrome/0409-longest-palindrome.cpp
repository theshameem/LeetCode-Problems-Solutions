class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> countS;
        for(char i: s) countS[i]++;
        
        int evenSum = 0, cnt = 0;
        for(auto x: countS){
            if(x.second % 2 != 0) ++cnt;
        }
        
        int ans = s.size();
        if(cnt > 1){
            ans -= cnt;
            ++ans;
        }
        
        return ans;
    }
};