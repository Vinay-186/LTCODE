class Solution {
public:
    vector<vector<string>> res;
    int n;
    vector<vector<int>> dp;
    bool p(string& s, int i, int j){
        if(i > j) return true;
        if(s[i] != s[j]) return false;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = p(s,i+1,j-1);
    }
    void helper(string& s,int ind,vector<string>& ans){
        if(ind == n){
            res.push_back(ans);
            return ;    
        }
        for(int i = ind; i < n; i++){
            if(p(s,ind, i)){
                ans.push_back(s.substr(ind, i-ind+1));
                helper(s,i+1,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        dp.resize(n, vector<int>(n,-1));
        vector<string> ans;
        helper(s,0,ans);
        return res;
    }
};