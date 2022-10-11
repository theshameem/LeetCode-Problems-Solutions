class Solution {
public:
    bool checkEquality(vector<int> A, vector<int> B){
        for(int i = 0; i < 26; i++){
            if(A[i] != B[i]) return false;
        }    
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> F1(26, 0);
        vector<int> F2(26, 0);
        
        for(auto i: s1) F1[i - 'a']++;
        
        int i = 0, j = 0;
        while(j < s2.size()){
            char ch = s2[j];
            F2[ch - 'a']++;
            int len = j - i + 1;
            
            if(len == s1.size()){
                if(checkEquality(F1, F2)) return true;
            }
            
            if(len < s1.size()){
                j++;
            } else {
                F2[s2[i] - 'a']--;
                i++, j++;
            }
        }
        return false;
    }
};