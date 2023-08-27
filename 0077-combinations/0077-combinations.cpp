class Solution {
public:
    
    void helper(int num, int n,int k, vector<int>& ans, vector<vector<int>>& res){
        if(num == n+1){
            if((int)ans.size() == k){
                res.push_back(ans);
            }
            return;
        }
        helper(num + 1, n, k, ans, res);
        ans.push_back(num);
        helper(num+1, n, k, ans, res);
        ans.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> res;
        helper(1, n, k, ans, res);
        return res;
    }
};