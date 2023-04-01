class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    int delrow[4] = {-1,1,0,0};
    int delcol[4] = {0,0,-1,1};
    void dfs(int i, int j, vector<vector<int>>& g){
        vis[i][j] = 1;
        for(int t = 0; t < 4; t++){
            int nrow = i + delrow[t];
            int ncol = j + delcol[t];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && g[nrow][ncol]){
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, g);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(); 
        n = grid[0].size();
        vis.assign(m, vector<int>(n,0));
        for(int j = 0; j < n; j++){
            if(!vis[0][j] && grid[0][j]) dfs(0,j, grid);
            if(!vis[m-1][j] && grid[m-1][j]) dfs(m-1, j, grid);
        }
        for(int i = 0; i < m; i++){
            if(!vis[i][0] && grid[i][0]) dfs(i,0, grid);
            if(!vis[i][n-1] && grid[i][n-1]) dfs(i, n-1, grid);
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(!vis[i][j] && grid[i][j]) count++;
            }
        }
        return count;
    }
};