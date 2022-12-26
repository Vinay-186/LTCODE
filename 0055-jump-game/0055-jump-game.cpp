class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,0);
        dp[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(i + nums[i] >= n-1){dp[i] = true; continue;}
            if(nums[i] == 0) {dp[i] = false;continue;}
            int m = nums[i];
            bool var = false;
            for(int j = 1; j <= m; j++){
                if(i + j <= n-1 && dp[i + j] == 1){
                    var = true;
                    break;
                }
            }
            dp[i] = var;
        }
        return dp[0];
    }
};