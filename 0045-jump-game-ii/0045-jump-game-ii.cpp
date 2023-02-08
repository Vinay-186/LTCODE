class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n,1e8);
       dp[n-1] = 0;
       for(int i = n-2; i >= 0; i--){
          if(nums[i] == 0) continue;
          else{
                int mini = 1e8;
                for(int j = i + nums[i]; j >= i + 1; j--) mini = min(mini,(j < n)? 1 + dp[j] : 1);
                dp[i] = mini;
           }
       }
       return dp[0];
    }
};