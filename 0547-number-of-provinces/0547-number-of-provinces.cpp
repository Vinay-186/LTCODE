class Solution {
public:
    vector<int> visited;
    void dfs(int ind, vector<vector<int>>& adj){
        visited[ind] = 1;
        for(int& i : adj[ind]){
            if(!visited[i]){
                dfs(i, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        int n = c.size();
        visited.assign(n,0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(c[i][j]){
                    adj[i].push_back(j);
                    if(i != j) adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj);
            }
        }
        return count;
    }
};