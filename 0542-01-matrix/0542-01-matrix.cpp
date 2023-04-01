class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0)), ans(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto [x,y] = q.front();
                q.pop();
                ans[x][y] = step;
                if(x -1 >= 0 && !vis[x-1][y]) q.push({x-1,y}), vis[x-1][y]++;
                if(x +1 < m && !vis[x+1][y]) q.push({x+1,y}), vis[x+1][y]++;
                if(y -1 >= 0 && !vis[x][y-1]) q.push({x,y-1}), vis[x][y-1]++;
                if(y +1 < n && !vis[x][y+1]) q.push({x,y+1}), vis[x][y+1]++;
            }
            step++;
        }
        return ans;
    }
};