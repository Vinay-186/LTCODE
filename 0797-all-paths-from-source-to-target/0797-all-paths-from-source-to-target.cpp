class Solution {
public:
    vector<vector<int>> res;
    int n;
    void helper(vector<vector<int>>& g,int ind, vector<int>& ans){
        if(ind == n-1){
            res.push_back(ans);
            return;
        }
        for(int i : g[ind]){
                ans.push_back(i);
                helper(g,i,ans);
                ans.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> ans;
        n = graph.size();
        ans.push_back(0);
        helper(graph, 0, ans);
        return res;
    }
};