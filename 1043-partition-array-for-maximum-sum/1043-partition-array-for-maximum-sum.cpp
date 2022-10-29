class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int ind = n-1; ind >= 0; ind--){
            int maxVal = 0, maxSum = 0;
            for(int j = ind; j < min(ind+k,n); j++){
                maxVal = max(maxVal,arr[j]);
                int sum = maxVal * (j - ind + 1) + dp[j+1];
                maxSum = max(maxSum, sum);
            }
            dp[ind] = maxSum;
        }
        return dp[0];
    }
};