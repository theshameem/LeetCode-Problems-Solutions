class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> st;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(abs(i - j) > k){
                st.erase(nums[j]);
                j++;
            }
            if(st.find(nums[i]) != st.end()) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};