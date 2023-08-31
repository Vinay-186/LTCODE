class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        const int INF = 1e9;
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            int tapS = max(0, i - ranges[i]);
            int tapE = min(n, i + ranges[i]);
            for(int j = tapS; j <= tapE; j++){
                dp[tapE] = min(dp[tapE], dp[j] + 1);
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};