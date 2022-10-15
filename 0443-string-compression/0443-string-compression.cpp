class Solution {
public:
    int compress(vector<char>& chars) {
        int pos = 0;
        for(int i = 0; i < chars.size(); i++){
            int cnt = 1;
            while(i + 1 < chars.size() && chars[i] == chars[i + 1]){
                ++cnt, ++i;
            }
            chars[pos++] = chars[i];
            string tmp = to_string(cnt);
            if(cnt > 1) for(auto x: tmp) chars[pos++] = x; 
        }
        return pos;
    }
};