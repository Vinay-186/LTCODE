class Solution {
public:
    void dfs(int ind, vector<int>& vis, vector<vector<int>> & adj){
        vis[ind] = 1;
        for(int i : adj[ind]){
            if(!vis[i]) dfs(i, vis, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int>& i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int count = 0;
        for(int i = 0; i <n; i++){
            if(!vis[i]) dfs(i, vis, adj), count++;
        }
        return count;
    }
};