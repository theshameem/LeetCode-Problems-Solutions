class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        string tmp = "";
        for(int i = 0; i < haystack.size(); i++){
            if(tmp.size() < needle.size()){
                tmp += haystack[i];
            }
            if(tmp == needle){
                // cout << needle << " " << i << endl;
                return i - tmp.size() + 1;
            } else if(tmp.size() == needle.size()) {
                tmp.erase(tmp.begin());
            }
        }
        return -1;
    }
};