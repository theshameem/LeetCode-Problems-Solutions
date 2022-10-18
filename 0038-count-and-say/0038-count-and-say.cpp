class Solution {
public:
    string findNTHSay(string s){
        map<int, int> mp; //map<cnt, val> mp;
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
    
    string countAndSay(int n) {
        vector<string> ans;
        ans.push_back("1");
        
        for(int i = 1; i < n; i++){
            string nThSay = findNTHSay(ans[i - 1]);
            ans.push_back(nThSay);
        }
        
        return ans[n - 1];
    }
};