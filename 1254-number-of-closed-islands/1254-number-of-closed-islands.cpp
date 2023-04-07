class Solution {
public:
    int m, n;
    int delrow[4] = {+1,-1,0,0};
    int delcol[4] = {0,0,+1,-1};
    void dfs(int i,int j,vector<vector<int>>& g,vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int t = 0; t < 4; t++){
            int nrow = i + delrow[t];
            int ncol = j + delcol[t];
            if(nrow < 0 || nrow == m || ncol < 0 || ncol == n || vis[nrow][ncol]|| g[nrow][ncol] ) continue;
            dfs(nrow, ncol, g, vis);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i = 0; i < n; i++){
            if(!vis[0][i] && !grid[0][i]) dfs(0,i,grid,vis);
            if(!vis[m-1][i] && !grid[m-1][i]) dfs(m-1,i,grid,vis);
        }
        for(int i = 0; i < m; i++){
            if(!vis[i][0] && !grid[i][0]) dfs(i,0,grid,vis);
            if(!vis[i][n-1] && !grid[i][n-1]) dfs(i,n-1,grid,vis);
        }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && !grid[i][j]){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};