class Solution {
public:
    vector<vector<int>> res;
    vector<int> seen;
    int n;
    void helper(vector<vector<int>>& g,int ind, vector<int>& ans){
        if(ind == n-1){
            res.push_back(ans);
            return;
        }
        for(int i : g[ind]){
            if(seen[i] != 1){
                ans.push_back(i);
                seen[i] = 1;
                helper(g,i,ans);
                seen[i] = 0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> ans;
        n = graph.size();
        seen.resize(n,0);
        ans.push_back(0);
        seen[0] = 1;
        helper(graph, 0, ans);
        return res;
    }
};