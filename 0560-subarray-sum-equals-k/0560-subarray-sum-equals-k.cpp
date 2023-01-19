class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0, res = 0;
        for(int& i : nums){
            sum += i;
            if(mp.find(sum - k) != mp.end()) res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};