class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> st;
        
        int ans = 0, sign = 1;
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            
            if(isdigit(ch)){
                long long int num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = (num * 10) + s[i] - '0';
                    i++;
                }
                --i;
                ans += (num * sign);
                sign = 1;
            } else if(ch == '('){
                st.push({ans, sign});
                ans = 0, sign = 1;
            } else if(ch == ')'){
                ans = st.top().first + (st.top().second * ans);
                st.pop();
            } else if(ch == '-'){
                sign *= -1;
            }
        }
        
        return ans;
    }
};