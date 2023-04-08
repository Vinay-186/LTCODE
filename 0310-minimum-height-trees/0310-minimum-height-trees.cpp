class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0), ans;
        for(auto &e : edges){ 
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++, degree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n;i++){
            if(degree[i]==1) q.push(i), degree[i]--; 
        } 
        
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0; i<s;i++){
                int curr = q.front(); q.pop();
                ans.push_back(curr);
                for(auto child : graph[curr]){
                    degree[child]--;
                    if(degree[child]==1) q.push(child);   
                }
            }
        }
        return ans;
        
    }
};