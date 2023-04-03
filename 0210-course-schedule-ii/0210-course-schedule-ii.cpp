class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>(0));
        vector<int> indeg(n, 0);
        for(vector<int>& i : pre){
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        queue<int> q;
        for(int i = 0 ;i < n; i++){
            if(!indeg[i]) q.push(i);
        }
        int count = 0;
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(int j : adj[node]){
                if(--indeg[j] == 0) q.push(j);
            }
        }
        reverse(ans.begin(), ans.end());
        if(count == n) return ans;
        return {};
    }
};