class Solution {
public:
    int n; 
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s) {
        n = s.size();
        string s2 = string(s.rbegin(), s.rend());
        dp.assign(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n ;j++){
                if(s[i-1] == s2[j-1]) dp[i][j]= 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};