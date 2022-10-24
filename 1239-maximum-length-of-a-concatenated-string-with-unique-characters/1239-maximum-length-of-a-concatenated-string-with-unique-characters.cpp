class Solution {
public:
    int n;
    vector<string> ar;
    
    bool findNoDuplicate(string s, string t){
        map<char, int> mp;
        for(char i: s) mp[i]++;
        for(char i: t) mp[i]++;
        
        for(auto i: mp){
            if(i.second > 1) return false;
        }
        
        return true;
    }
    
    int solve(int pos, string s){
        if(pos == n){
            // cout << s << endl;
            // if(!findNoDuplicate(s, "")) return 0;
            return s.size();
        }
        int res = 0;
        
        if(findNoDuplicate(s, ar[pos])){
            res += solve(pos + 1, s + ar[pos]);
        }
        int res2 = solve(pos + 1, s);
        
        return max(res, res2);
    }
    
    int maxLength(vector<string>& arr) {
        n = arr.size();
        ar = arr;
        return solve(0, "");
    }
};