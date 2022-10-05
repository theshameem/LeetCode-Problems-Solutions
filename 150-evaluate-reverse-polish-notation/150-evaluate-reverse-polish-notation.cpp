class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        long long int ans = stoi(tokens[0]), valOne, valTwo;
        for(auto i: tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                ans = 0;
                valTwo = st.top();
                st.pop();
                valOne = st.top();
                st.pop();
                if(i == "+"){
                    ans = (valOne + valTwo);
                } else if(i == "-"){
                    ans = (valOne - valTwo);
                } else if(i == "*"){
                    ans = (valOne * valTwo);
                } else if(i == "/"){
                    ans = (valOne / valTwo);
                }
                st.push(ans);
            }  else {
                st.push(stoi(i));
            }
        }
        return ans;
    }
};