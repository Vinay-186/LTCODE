class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int sz = nums.size();
        vector<vector<int>> dp(sz,vector<int>(sz,0));
        for(int i = sz -2; i >= 1; i--){
            for(int j = i; j <= sz-2; j++){
                int maxi = INT_MIN;
                for(int k = i; k <= j; k++)
                    maxi = max(maxi,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                dp[i][j] = maxi;
            }
        }
        return dp[1][sz-2];
    }
};