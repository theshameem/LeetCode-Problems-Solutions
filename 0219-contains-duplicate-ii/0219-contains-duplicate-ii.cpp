class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 1) return false;
        
        int i = 0, j = 1;
        map<int, int> mp;
        mp[nums[0]]++;
        
        while(i < j && j < len){   
            if(abs(i - j) > k){
                mp[nums[i]]--;
                if(mp[nums[i]] < 1) mp.erase(nums[i]);
                i++;
                continue;
            }
            
            if(mp[nums[j]] > 0) return true;
            
            if(j + 1 == len){
                mp[nums[i]]--;
                if(mp[nums[i]] < 1) mp.erase(nums[i]);
                ++i;
            } else {
                mp[nums[j]]++;
                ++j;
            }
        }
        return false;
    }
};