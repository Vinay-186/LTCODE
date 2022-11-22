class Solution {
public:
    int numSquares(int n) {
       int sz = pow(n, 0.5);
       vector<vector<int>> dp(sz+1, vector<int>(n+1,1e8));
       dp[0][n] = 0;
       for(int i = 1; i <= sz; i++){
           for(int j = n; j >= 0; j--){
               int include = 1e8;
               if(j + i*i <= n)include = 1 + dp[i][j+i*i];
               int exclude = dp[i-1][j];
               dp[i][j] = min(include, exclude);
           }
       }
       return dp[sz][0];
    }
};