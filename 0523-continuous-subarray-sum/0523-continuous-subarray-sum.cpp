class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 0;
        int n = nums.size();
        int p = 0;
        for(int i = 0;i < n; i++){
            p += nums[i];
            if(mp.find(p % k) == mp.end()) mp[p % k] = i + 1;
            else if(i - mp[p % k] >= 1) return true;
        }
        return false;
    }
};