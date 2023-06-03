class Node{
  public : 
    int node, dis, stops;
    Node(int node, int dis, int stops){
        this->node = node;
        this->dis = dis;
        this->stops = stops;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(vector<int>& i : flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<Node> q;
        q.push({src, 0, 0});
        while(!q.empty()){
            auto [node, dis, stops] = q.front();
            q.pop();
            if(stops > k) continue;
            for(auto& iter : adj[node]){
                auto [adjNode, edgeW] = iter;
                if(edgeW + dis < dist[adjNode] && stops <= k){
                    q.push(Node(adjNode, edgeW+ dis, stops + 1));
                    dist[adjNode] = edgeW + dis;
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};