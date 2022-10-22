class Solution {
public:
    int firstUniqChar(string s) {
        int arr[29];
        memset(arr, 0, sizeof arr);
        for(char ch: s){
            arr[ch - 'a']++;
        }
        
        for(int i = 0; i < s.size(); i++){
            if(arr[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
};