class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int ind = n-1; ind >= 0; ind--){
            int ans = INT_MIN;
            for(int j = ind; j < ind + k && j < n; j++)
                ans = max(ans, (*max_element(arr.begin()+ind, arr.begin() + j + 1)) * (j - ind + 1) + dp[j+1]);
            dp[ind] = ans;
        }
        return dp[0];
    }
};