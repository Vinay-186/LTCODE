class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n,vector<int>(0));
        for(int i = 0; i < n; i++){
            for(int j : graph[i]){
                adj[j].push_back(i);
            }
        }
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++){
            for(int j : adj[i]) indeg[j]++;
        }
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < n; i++){
            if(!indeg[i]) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int i : adj[node]){
                if(--indeg[i] == 0) q.push(i);
            }
        }
        
        sort(topo.begin(), topo.end());
        return topo;
    }
};