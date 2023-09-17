class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;
        int endingMask = (1 << n) -1;
        vector<vector<int>> seen(n, vector<int>(endingMask, 0));
        vector<vector<int>> q;
        for(int i = 0; i <n; i++){
            q.push_back({i, (1 << i)});
            seen[i][1 << i] = 1;
        }
        
        int steps = 0;
        while(!q.empty()){
            vector<vector<int>> next_q;
            for(int i = 0; i < q.size(); i++){
                int node = q[i][0];
                int mask = q[i][1];
                for(int neighbour : graph[node]){
                    int nextMask = mask | (1 << neighbour);
                    if(nextMask == endingMask) return 1+steps;
                    if(!seen[neighbour][nextMask]){
                        seen[neighbour][nextMask] =1;
                        next_q.push_back({neighbour, nextMask});
                    }
                }
            }
            steps++;
            q = next_q;
        }
        return -1;
    }
};