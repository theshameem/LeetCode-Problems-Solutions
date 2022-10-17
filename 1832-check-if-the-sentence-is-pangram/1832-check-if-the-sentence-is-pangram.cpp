class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> mp;
        for(char i: sentence){
            mp[i]++;
        }
        return mp.size() == 26;
    }
};