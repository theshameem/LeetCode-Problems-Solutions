class Solution {
public:
    static bool cmp(string A, string B){
        if(A + B < B + A) return 1;
        return 0;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto i: nums) s.push_back(to_string(i));
        
        string ans = "";
        sort(s.begin(), s.end(), cmp);
        reverse(s.begin(), s.end());
        for(auto i: s){
            ans += i;
        }
        int i = 0;
        while(i < ans.size() - 1 && ans[i] == '0'){
            ans.erase(ans.begin());
        }
        return ans;
    }
};