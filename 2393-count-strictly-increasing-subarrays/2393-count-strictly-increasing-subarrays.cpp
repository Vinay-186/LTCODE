class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 1);
        
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                dp[i] = 1 + dp[i+1];
            }
        }
        return accumulate(dp.begin(), dp.end(), 0ll);
    }
};