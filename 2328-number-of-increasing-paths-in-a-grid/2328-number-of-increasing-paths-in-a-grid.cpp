class Solution {
public:
    int m , n;
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int dfs(vector<vector<int>>& g, int i, int j){
        if(dp[i][j] != 0) return dp[i][j];
        
        int ans = 1;
        for(int t = 0; t< 4; t++){
            int nrow = i + dx[t];
            int ncol = j + dy[t];
            if(nrow < 0 || nrow == m || ncol < 0 || ncol == n || g[nrow][ncol] >= g[i][j])
            {
              continue;  
            } 
            ans += dfs(g, nrow, ncol);
            ans %= mod;
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = (ans + dfs(grid, i, j)) % mod;
            }
        }
        return ans;
    }
};