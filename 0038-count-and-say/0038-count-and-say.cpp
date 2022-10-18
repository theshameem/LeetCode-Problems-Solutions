class Solution {
public:
    string findNTHSay(string s){
        string ans = "";
        for(int i = 0; i < s.size(); ){
            int j = i, cnt = 0;
            while(j < s.size() && s[i] == s[j]){
                ++cnt, ++j;
            }
            ans += to_string(cnt) + s[i];
            i = j;
        }
        return ans;
    }
    
    void findNthSayByRecursion(int n, string &ans){
        if(n == 1){
            ans = "1";
            return;
        }
        findNthSayByRecursion(n - 1, ans);
        string s = ans;
        ans = "";
        for(int i = 0; i < s.size(); ){
            int j = i, cnt = 0;
            while(j < s.size() && s[i] == s[j]){
                ++cnt, ++j;
            }
            ans += to_string(cnt) + s[i];
            i = j;
        }
    }
    
    string countAndSay(int n) {
        string ans = "1";
        
        for(int i = 1; i < n; i++){
            ans = findNTHSay(ans);
        }
        
        string tmp = "";
        
        findNthSayByRecursion(n, tmp);
        
        return tmp;
    }
};