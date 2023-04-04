//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private : 
    void topoSort(int ind, vector<vector<int>>& adj, vector<int>& vis, stack<int>& topo){
        vis[ind] = 1;
        for(int& j : adj[ind]){
            if(!vis[j])topoSort(j, adj, vis, topo);
        }
        topo.push(ind);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<int>> adj(N, vector<int>(0));
        map<pair<int,int>, int> mp;
        for(int i = 0 ;i < M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            mp[{edges[i][0], edges[i][1]}] = edges[i][2];
        }
        vector<int> dist(N, 1e8);
        vector<int> vis(N, 0);
        stack<int> topo;
        for(int i = 0; i < N; i++){
            if(!vis[i]) topoSort(i, adj, vis, topo);
        }
        dist[0] = 0;
        while(!topo.empty()){
            int node = topo.top();
            topo.pop();
            for(int& i : adj[node]){
                dist[i] = min(dist[i], dist[node] + mp[{node, i}]);
            }
        }
        for(int i = 0; i < N; i++){
            if(dist[i] == 1e8) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends