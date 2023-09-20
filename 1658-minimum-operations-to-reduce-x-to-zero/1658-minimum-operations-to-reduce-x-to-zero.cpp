class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0,n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0) - x;
        if(k == 0) return n;
        int maxi = -1;
        map<int,int> mp;
        for(int i = 0; i <n; i++){
            sum += nums[i];
            int rem = sum - k;
            if(sum == k) maxi = max(maxi, i+1);
            if(mp.find(rem) != mp.end()){
                int len = i - mp[rem];
                maxi = max(maxi, len);
            }
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        if(maxi == -1) return -1;
        return n - maxi;
    }
};