class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        
        map<char, int> windowT, curWindow;
        for(auto i: t){
            if(windowT.count(i)) windowT[i]++;
            else windowT[i] = 1;
        }
        
        int have = 0, need = windowT.size();
        int resL = 0, resR = 0, resLen = INT_MAX, j = 0;
        
        for(int i = 0; i < s.size(); i++){
            char curr = s[i];
            if(curWindow.count(curr)){
                curWindow[curr]++;
            } else {
                curWindow[curr] = 1;
            }
               
            if(windowT.count(curr) && windowT[curr] == curWindow[curr]){
                have++;
            }
               
            while(have == need){
                int len = i - j + 1;
                if(len < resLen){
                    resR = i;
                    resL = j;
                    resLen = len;
                }
                
                curWindow[s[j]]--;
                if(windowT.count(s[j]) && curWindow[s[j]] < windowT[s[j]]){
                    have--;
                }
                j++;
            }
        }
        if(resLen == INT_MAX) return "";
        string ans = "";
        for(int i = resL; i <= resR; i++) ans += s[i];
        return ans;
    }
};