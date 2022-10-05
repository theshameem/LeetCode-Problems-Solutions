class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mp;
        int ans = 0, i = 0, j = 0;
        
        while(j < fruits.size()){
            mp[fruits[j]]++;
            while(mp.size() > 2){
                if(mp[fruits[i]] == 1){
                    mp.erase(fruits[i]);
                } else {
                    mp[fruits[i]]--;
                }
                ++i;
            }
            ans = max(ans, j - i + 1);
            ++j;
        }
        return ans;
    }
};