class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    int delrow[4] = {-1,+1,0,0};
    int delcol[4] = {0,0,-1,1};
    void dfs(int i, int j, vector<vector<char>>& b){
        vis[i][j] = 1;
        for(int t = 0; t < 4; t++){
            int nrow = i + delrow[t];
            int ncol = j + delcol[t];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && b[nrow][ncol] == 'O'){
                dfs(nrow, ncol, b);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vis.assign(m, vector<int>(n,0));
        for(int j = 0; j < n; j++){
            if(!vis[0][j] && board[0][j] == 'O') dfs(0,j, board);
            if(!vis[m-1][j] && board[m-1][j] == 'O') dfs(m-1, j, board);
        }
        for(int i = 0; i < m ; i++){
            if(!vis[i][0] && board[i][0] == 'O') dfs(i,0,board);
            if(!vis[i][n-1] && board[i][n-1] == 'O') dfs(i,n-1, board);
        }
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};