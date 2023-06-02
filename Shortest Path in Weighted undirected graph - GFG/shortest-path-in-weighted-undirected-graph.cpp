//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(vector<int>& i : edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1, 0);
        for(int i = 1; i <= n; i++) parent[i] = i;
        int src = 1, dest = n;
        dist[src] = 0;
        parent[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            for(auto& i : adj[node]){
                int adjNode = i.first;
                int edgeW = i.second;
                if(dis + edgeW < dist[adjNode]){
                    parent[adjNode] = node;
                    dist[adjNode] = dis + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        if(dist[dest] == 1e9) return {-1};
        int cur_node = dest;
        vector<int> final_ans;
        while(cur_node != 0){
            final_ans.push_back(cur_node);
            cur_node = parent[cur_node];
        }
        reverse(final_ans.begin(), final_ans.end());
        return final_ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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