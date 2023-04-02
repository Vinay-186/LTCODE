class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    int delrow[4]  = {-1,0, 0,1};
    int delcol[4]  = {0,-1,1,0};
    int b_x, b_y;
    void dfs(int i, int j, vector<vector<int>>& g, vector<pair<int,int>>& island){
        vis[i][j] = 1;
        island.push_back({i-b_x, j-b_y});
        for(int t = 0; t < 4; t++){
            int nrow = i + delrow[t];
            int ncol = j + delcol[t];
            if(nrow < 0 || nrow == m || ncol < 0 || ncol == n || vis[nrow][ncol] || !g[nrow][ncol]) continue;
            dfs(nrow, ncol, g, island);
        }
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n,0));
        set<vector<pair<int,int>>> islands;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j]){
                    vector<pair<int,int>> island;
                    b_x = i, b_y = j;
                    dfs(i, j , grid, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
};
