class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        for(int i = 2; i < s.size(); i++){
            char a = s[i];
            char b = s[i - 1];
            char c = s[i - 2];
            
            if(a != b && a != c && b != c) ++ans;
        }
        return ans;
    }
};