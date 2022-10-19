class Solution {
public:
    int countWords(string s){
        int space = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') ++space;
        }
        return ++space;
    }
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> mp;
        int mx = 0;
        string ans = "";
        for(int i = 0; i < messages.size(); i++){
            int wordsCount = countWords(messages[i]);
            mp[senders[i]] += wordsCount;            
        }
        
        for(auto i: mp){
            if(i.second == mx){
                if(i.first > ans){
                    ans = i.first;
                }
            } else if(i.second > mx){
                mx = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};