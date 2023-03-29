class Solution {
public:
    vector<vector<int>> vis;
    int n, m;
    int orig, color;
    void dfs(int i, int j, vector<vector<int>> & grid){
        vis[i][j] = 1;
        grid[i][j] = color;
        int u_i = i-1, u_j = j,l_i = i+1, l_j = j,b_i = i, b_j = j-1, f_i = i, f_j = j+1;
        if(u_i >= 0 && grid[u_i][u_j] == orig  && !vis[u_i][u_j]) dfs(u_i, u_j, grid);
        if(l_i < m && grid[l_i][l_j] == orig && !vis[l_i][l_j]) dfs(l_i, l_j, grid);
        if(b_j >= 0 && grid[b_i][b_j] == orig && !vis[b_i][b_j]) dfs(b_i, b_j, grid);
        if(f_j < n && grid[f_i][f_j] == orig && !vis[f_i][f_j]) dfs(f_i, f_j, grid);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        orig = image[sr][sc];
        this->color = color;
        vis.assign(m, vector<int>(n, 0));
        dfs(sr, sc, image);
        return image;
    }
};