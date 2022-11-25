class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long int ans = 0, mod = 1e9 + 7;
        
        for(int i = 0; i <= arr.size(); i++){
            while(st.size() && (i == arr.size() || arr[st.top()] >= arr[i])){
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                
                long long int cnt = (mid - left) * (right - mid) % mod;
                
                ans += (cnt * arr[mid]) % mod;
                ans %= mod;
            }
            st.push(i);
        }
        return (int)ans;
    }
};