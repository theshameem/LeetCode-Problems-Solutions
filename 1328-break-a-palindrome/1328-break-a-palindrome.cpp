class Solution {
public:
    string breakPalindrome(string palindrome) {
        int mid = -1, len = palindrome.size();
        if(len % 2 == 1){
            mid = (len / 2);
        }
        string ans = "";
        for(int i = 0; i < len; i++){
            if(mid == i) continue;
            if(palindrome[i] > 'a'){
                ans = palindrome;
                ans[i] = 'a';
                break;
            }
            if(i == len - 1){
                ans = palindrome;
                ans[i] = 'b';
            }
        }
        return ans;
    }
};