class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<int,int>> q;
        int n = g.size();
        int m = g[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j++){
                if(g[i][j]==1) count++;
                if(g[i][j]==2) q.push({i,j});
            }
        }
        int min = 0;
        while(!q.empty()){
            if(count == 0) return min;
            q.push({-1,-1});
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto nd = q.front();
                q.pop();
                int x = nd.first, y = nd.second;
                if(x == -1 && y == -1) continue;
                if(x-1 >= 0 && g[x-1][y] == 1){
                    q.push({x-1,y});
                    g[x-1][y] = 2;
                    count--;
                }
                if(x+1 < n && g[x+1][y] == 1){
                    q.push({x+1,y});
                    g[x+1][y] = 2;
                    count--;
                }
                if(y-1 >= 0 && g[x][y-1] == 1){
                    q.push({x,y-1});
                    g[x][y-1] = 2;
                    count--;
                }
                if(y+1 < m && g[x][y+1] == 1){
                    q.push({x,y+1});
                    g[x][y+1] = 2;
                    count--;
                }
            }
            min++;
        }
        return count > 0 ? -1 : 0;
    }
};