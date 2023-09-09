class Solution {
public:
    vector<int> dp;
    int ans(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int cnt = 0;
        for(int num : nums){
            if(target - num >= 0)
                cnt += ans(nums, target - num);
        }
        return dp[target] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.assign(target+ 1, -1);
        return ans(nums, target);
    }
};