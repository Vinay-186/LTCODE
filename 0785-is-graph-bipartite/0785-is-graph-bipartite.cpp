class Solution {
public:
    bool bfs(int ind, vector<vector<int>>& adj, vector<int>& color){
        queue<int> q;
        color[ind] = 0;
        q.push(ind);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int& i : adj[node]){
                if(color[i] == -1){
                    color[i] = !color[node];
                    q.push(i);
                }else if(color[i] == color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(bfs(i, adj, color) == false) return false;   
            }
        }
        return true;
    }
};