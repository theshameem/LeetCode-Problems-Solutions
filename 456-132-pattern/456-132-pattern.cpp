class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        vector<int> curMin(nums.size());
        
        curMin[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) curMin[i] = min(curMin[i - 1], nums[i]);
        
        for(int i = nums.size() - 1; i >= 0; i--){
            while(st.size() && st.top() <= curMin[i]) st.pop();
            if(st.size() && st.top() < nums[i]) return true;
            st.push(nums[i]);
        }
        return false;
    }
};