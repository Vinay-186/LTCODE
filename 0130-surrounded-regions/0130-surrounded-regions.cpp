class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        map<pair<int,int>, int> o;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O') q.push({i,j}), vis[i][j] = 1;
                }else if(i > 0 && j > 0 && board[i][j] == 'O'){
                    o[{i,j}] = 1;
                }
            }
        }
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto [x,y]= q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nrow = x + delrow[j];
                    int ncol = y + delcol[j];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                        o[{nrow,ncol}] = 0;
                    }
                }
            }
        }
        for(auto& i : o){
            if(i.second == 1) board[i.first.first][i.first.second] = 'X';
        }
    }
};