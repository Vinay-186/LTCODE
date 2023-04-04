//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
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
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int node = q.front();
                q.pop();
                for(int& j : adj[node]){
                    q.push(j);
                    dist[j] = min(dist[j],dist[node] +  mp[{node, j}]);
                }
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