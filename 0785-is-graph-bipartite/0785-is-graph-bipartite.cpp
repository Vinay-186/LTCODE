class Solution {
public:
    bool dfs(int ind ,int par, vector<vector<int>>& adj, vector<int>& color){
        if(par == -1) color[ind] = 0;
        else color[ind] = !color[par];
        
        for(int& i : adj[ind]){
            if(i == par) continue;
            if(color[i] == -1){
               if(!dfs(i, ind, adj, color)) return false;
            }else if(color[i] == color[ind]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(dfs(i, -1, adj, color) == false) return false;   
            }
        }
        return true;
    }
};