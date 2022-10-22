class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char, int> mp;
        for(char i: stones) mp[i]++;
        
        int ans = 0;
        for(char i: jewels){
            if(mp.count(i)){
                ans += mp[i];
            }
        }
        return ans;
    }
};