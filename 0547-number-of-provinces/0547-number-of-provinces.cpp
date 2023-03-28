class Solution {
public:
    vector<int> visited;
    void bfs(int ind, vector<vector<int>>& adj){
        queue<int> q;
        q.push(ind);
        visited[ind]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int& i : adj[node]){
                if(!visited[i]){
                    visited[i] = 1;
                    q.push(i);
                }
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
                bfs(i, adj);
            }
        }
        return count;
    }
};