class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    int delrow[4]  = {-1,0, 0,1};
    int delcol[4]  = {0,-1,1,0};
    void dfs(int i, int j, vector<vector<int>>& g, set<pair<int,int>>& island){
        vis[i][j] = 1;
        for(int t = 0; t < 4; t++){
            int nrow = i + delrow[t];
            int ncol = j + delcol[t];
            if(nrow < 0 || nrow == m || ncol < 0 || ncol == n || vis[nrow][ncol] || !g[nrow][ncol]) continue;
            island.insert({nrow, ncol});
            dfs(nrow, ncol, g, island);
        }
    }
    bool same(set<pair<int,int>>& s1, set<pair<int,int>>& s2){
        if(s1.size() != s2.size()) return false;
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        int diffx = 0, diffy = 0;
        diffx = (*it1).first - (*it2).first;
        diffy = (*it1).second- (*it2).second;
        it1++, it2++;
        while(it1 != s1.end() && it2 != s2.end()){
            int dx = (*it1).first - (*it2).first;
            int dy = (*it1).second- (*it2).second;
            if(diffx != dx || diffy != dy) return false;
            it1++, it2++;
        }
        return true;
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n,0));
        vector<set<pair<int,int>>> islands;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j]){
                    set<pair<int,int>> island = {{i,j}};
                    dfs(i, j , grid, island);
                    islands.push_back(island);
                }
            }
        }
        int n1 = islands.size();
        if(n1 == 0) return 0;
        int count = n1;
        map<int, int> mp;
        for(int i = 0; i < n1-1; i++){
            for(int j = i+1; j < n1; j++){
                if(same(islands[i], islands[j])){
                    if(mp.find(j) == mp.end()){
                        mp[j] = i;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};
