class Solution {
public:
    vector<vector<int>> dp;
    int helper(int i, int j, int m, int n){
        if(i == m || j == n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int down = helper(i+1, j, m, n);
        int right = helper(i, j+1, m, n);
        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return helper(0,0,m,n);
    }
};