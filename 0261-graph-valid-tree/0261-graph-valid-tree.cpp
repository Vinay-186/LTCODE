class Solution {
public:
    bool dfs(int node, int par, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(int& i : adj[node]){
            if(i == par) continue;
            if(vis[i]) return false;
            if(!dfs(i,node,adj, vis)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n, vector<int>(0));
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                if(count > 1) return false;
                if(!dfs(i,-1, adj, vis)) return false;
            }
        }
        return true;
    }
};