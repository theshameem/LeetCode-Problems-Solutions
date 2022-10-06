class Solution {
public:
    int numberOfSubstrings(string s) {
        int A = 0, B = 0, C = 0;
        
        int i = 0, j = 0, len = s.size(), ans = 0;
        while(i < len && i <= j && j <= len){
            if(A && B && C){
                ans += (len - j + 1);
                // cout << len - j + 1 << endl;
                if(s[i] == 'a') --A;
                else if(s[i] == 'b') --B;
                else --C;
                i++;
            } else {
                if(s[j] == 'a') ++A;
                else if(s[j] == 'b') ++B;
                else ++C;
                j++;
            }
        }
        return ans;
    }
};