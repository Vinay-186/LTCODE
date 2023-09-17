class Solution {
public:
    vector<vector<int>> cache;
    int endingMask;
    
    int dp(int node, int mask, vector<vector<int>>& graph){
        if(cache[node][mask] != 0) return cache[node][mask];
        if((mask & (mask-1)) == 0) return 0;
        cache[node][mask] = INT_MAX-1;
        for(int neighbour : graph[node]){
            if((mask & (1 << neighbour)) != 0){
                int alreadyVisited = dp(neighbour, mask, graph);
                int notVisited = dp(neighbour, mask ^ (1 << node), graph);
                int better = min(alreadyVisited, notVisited);
                cache[node][mask] = min(cache[node][mask] , 1 + better);
            }
        }
        return cache[node][mask];
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        endingMask = (1 << n) -1;
        cache.assign(n+1, vector<int>(endingMask+1));
        int best = INT_MAX;
        for(int node = 0; node < n; node++){
            best = min(best, dp(node, endingMask, graph));
        }
        return best;
    }
};