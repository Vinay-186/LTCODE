class Solution {
public:
    int n, m;
    vector<vector<int>> vis;
    vector<vector<int>> dp;
    int delrow[4] = {-1, 1, 0,0};
    int delcol[4] = {0,0, -1, 1};
    int dfs(int i, int j, vector<vector<int>>& mat){
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = 1;
        vis[i][j] = 1;
        for(int t = 0; t < 4; t++){
            int nrow = i + delrow[t];
            int ncol = j + delcol[t];
            if(nrow < 0 || ncol < 0 || nrow == m || ncol == n || mat[nrow][ncol] <= mat[i][j]) continue;
            maxi = max(maxi, 1 + dfs(nrow, ncol, mat));
        }
        return dp[i][j]= maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int maxi = 0;
        vis.assign(m, vector<int>(n, 0));
        dp.assign(m, vector<int>(n,-1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]) maxi = max(maxi, dfs(i, j, matrix));
            }
        }
        return maxi;
    }
};