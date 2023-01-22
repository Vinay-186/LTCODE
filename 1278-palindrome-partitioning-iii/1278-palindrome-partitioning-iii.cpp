class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        if(n == k) return 0;
        vector<vector<int>> d(n+1,vector<int>(k+1, 0));
        vector<vector<int>> dp(n+1,vector<int>(n,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                int t = dp[i+1][j-1];
                dp[i][j] = (s[i] == s[j])? t : 1 + t;
            }
        }
        for(int i = 1; i <= k; i++) d[n][i] = 1e8;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= k;j++){
                int mini = INT_MAX;
                for(int t = i; t < n; t++){
                    int cnt = (j==0)? 1e8 : dp[i][t] + d[t+1][j-1];
                    mini = min(mini,cnt);
                }
                d[i][j] = mini;
            }
            
        }
        return d[0][k];
    }
};