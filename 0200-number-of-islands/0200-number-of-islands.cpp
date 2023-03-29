class Solution {
public:
    vector<vector<int>> vis;
    int n, m;
    void dfs(int i, int j, vector<vector<char>> & grid){
        vis[i][j] = 1;
        int u_i = i-1, u_j = j,l_i = i+1, l_j = j,b_i = i, b_j = j-1, f_i = i, f_j = j+1;
        if(u_i >= 0 && grid[u_i][u_j] == '1' && !vis[u_i][u_j]) dfs(u_i, u_j, grid);
        if(l_i < m && grid[l_i][l_j] == '1' && !vis[l_i][l_j]) dfs(l_i, l_j, grid);
        if(b_j >= 0 && grid[b_i][b_j] == '1' && !vis[b_i][b_j]) dfs(b_i, b_j, grid);
        if(f_j < n && grid[f_i][f_j] == '1' && !vis[f_i][f_j]) dfs(f_i, f_j, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
       m = grid.size();
       n = grid[0].size();
       vis.assign(m, vector<int>(n, 0));
       int count = 0;
       for(int i = 0; i < m; i++){
           for(int j = 0; j < n; j++){
               if(grid[i][j] == '1' && !vis[i][j]){
                   count++;
                   dfs(i,j, grid);
               }
           }
       }
        return count;
    }
};