class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        map<char, int> mp;
        for(auto i: brokenLetters) mp[i]++;
        
        int i = 0;
        while(i < text.size()){
            if(mp.count(text[i])){
                while(i < text.size() && text[i] != ' ') ++i;
                ++i;
            } else if(text[i] == ' ' || i + 1 == text.size()) {
                ++i;
                ++ans;
            } else {
                ++i;
            }
        }
        
        return ans;
    }
};