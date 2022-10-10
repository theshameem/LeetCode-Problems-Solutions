class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char>mp;
        map<char, int> check;
        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i])){
                if(mp[s[i]] != t[i]) return false;
            } else {
                if(check[t[i]] > 0) return false;
                check[t[i]]++;
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
};