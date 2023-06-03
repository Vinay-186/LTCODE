class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(vector<int>& i : roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        int mod = int(1e9 + 7);
        vector<long long> dist(n, LONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            for(auto iter : adj[node]){
                auto [adjNode, edgeW] = iter;
                if(edgeW + dis < dist[adjNode]){
                    dist[adjNode] = edgeW + dis;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }else if(edgeW + dis == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};