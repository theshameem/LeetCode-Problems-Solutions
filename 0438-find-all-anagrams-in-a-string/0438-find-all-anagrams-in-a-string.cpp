class Solution {
public:
    bool checkEquality(vector<int> A, vector<int> B){
        for(int i = 0; i < 26; i++){
            if(A[i] != B[i]) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> F1(26, 0), F2(26, 0);
        
        for(auto i: p) F1[i - 'a']++;
        
        int i = 0, j = 0;
        vector<int> ans;
        
        while(j < s.size()){
            char ch = s[j];
            F2[ch - 'a']++;
            
            int len = j - i + 1;
            if(len == p.size()){
                if(checkEquality(F1, F2)){
                    ans.push_back(i);
                }
            }
            
            if(len < p.size()) {
                ++j;
            } else {
                F2[s[i] - 'a']--;
                i++, j++;
            }
        }
        return ans;
    }
};