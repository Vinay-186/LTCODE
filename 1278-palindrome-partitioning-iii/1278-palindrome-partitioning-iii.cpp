class Solution {
public:
    int n; 
    vector<vector<int>> dp, d;
    int p(string& s, int i, int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return  dp[i][j] = (s[i] == s[j])? p(s, i+1, j-1) : 1 + p(s, i+1, j-1);
    }
    int helper(string& s, int ind, int k){
        if(k < 0) return 1e8;
        if(ind == n){
            if(k == 0) return 0;
            return 1e8;
        }
        if(d[ind][k] != -1) return d[ind][k];
        int mini = INT_MAX;
        for(int i = ind; i < n;i++) mini = min(mini, p(s,ind, i) + helper(s,i+1,k-1));
        return d[ind][k] = mini;
    }
    int palindromePartition(string s, int k) {
        n = s.size();
        if(n == k) return 0;
        d.resize(n,vector<int>(k+1, -1));
        dp.resize(n, vector<int>(n,-1));
        return helper(s,0,k);
    }
};