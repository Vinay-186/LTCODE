class Solution {
public:
    vector<int> safe;
    bool dfs(int ind, vector<vector<int>>& g, vector<int>& vis, vector<int>& path){
        vis[ind] = 1;
        path[ind] = 1;
        // safe[ind] = 0;
        for(int& i : g[ind]){
            if(!vis[i] && dfs(i,g,vis,path) == true) {
                safe[ind] = 0;
                return true;
            }else if(path[i]){
                safe[ind] = 0;
                return true;
            }
        }
        path[ind] = 0;
        safe[ind] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        safe.assign(n,0);
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,graph, vis, path);
            }
        }
        for(int i = 0; i < n; i++){
            if(safe[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};