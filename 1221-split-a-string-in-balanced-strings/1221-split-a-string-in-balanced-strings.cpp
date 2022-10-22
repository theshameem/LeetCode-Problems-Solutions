class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0, ans = 0;
        for(auto i: s){
            if(i == 'L') ++l;
            else ++r;
            
            if(l == r) ++ans;
        }
        return ans;
    }
};