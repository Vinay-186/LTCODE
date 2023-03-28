//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> visited;
    vector<int> ans;
    // Function to return a list containing the DFS traversal of the graph.
    void helper(vector<int> adj[], int par, int ind){
        for(int& i : adj[ind]){
            if(i == par) continue;
            if(!visited[i]){
                ans.push_back(i);
                visited[i] = 1;
                helper(adj, ind, i);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        visited.assign(V, 0);
        visited[0] = 1;
        ans.push_back(0);
        helper(adj,0,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends