class Solution {
public:
    bool contains(pair<int,int> center,long long r, pair<int,int> point){
        long long diff_x = center.first -point.first;
        long long diff_y = center.second - point.second;
        long long dist_sq = (diff_x * diff_x) + (diff_y * diff_y);
        return dist_sq <= (r*r);
    }
    
    int bfs(vector<vector<int>>& adj, int idx){
        int n = adj.size();
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(idx);
        vis[idx] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int& i : adj[node]){
                if(vis[i]) continue;
                vis[i] = 1;
                q.push(i);
            }
        }
        return accumulate(vis.begin(), vis.end(), 0);
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(contains({bombs[i][0],bombs[i][1]}, bombs[i][2], 
                            {bombs[j][0],bombs[j][1]})){
                    adj[i].push_back(j);
                }
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i <n ; i++){
            maxi = max(maxi, bfs(adj, i));
        }
        return maxi;
    }
};
