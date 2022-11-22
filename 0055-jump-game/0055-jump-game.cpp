class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[n-1] = dp[n] = 1;
        for(int i = n-2; i >= 0; i--){
            bool f = false;
            for(int j = nums[i]; j >= 1; j--){
                if(f == true) break;
                f = (i + j >= n-1)? true : dp[i+j];
            }
            dp[i] = f;   
        }
        return dp[0];
    }
};