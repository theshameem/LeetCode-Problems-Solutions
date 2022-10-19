class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> mp;
        int mx = 0;
        string ans = "";
        for(int i = 0; i < messages.size(); i++){
            int wordsCount = count(messages[i].begin(), messages[i].end(), ' ') + 1;
            mp[senders[i]] += wordsCount;
            
            if(mp[senders[i]] > mx){
                mx = mp[senders[i]];
                ans = senders[i];
            } else if(mp[senders[i]] == mx){
                if(senders[i] > ans){
                    ans = senders[i];
                }
            }
        }
        
        return ans;
    }
};