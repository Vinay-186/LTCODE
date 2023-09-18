class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n+1, 0);
        vector<vector<int>> adj(n+1);
        for(vector<int>& relation : relations){
            adj[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        queue<int> q;
        for(int i = 1; i <= n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        int sem = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int node = q.front();
                q.pop();
                cnt++;
                for(int j : adj[node]){
                    if(--indegree[j] == 0){
                        q.push(j);
                    }
                }
            }
            sem++;
        }
        return cnt == n ? sem : -1;
    }
};