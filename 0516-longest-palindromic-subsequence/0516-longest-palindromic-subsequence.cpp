class Solution {
public:
    int n; 
    vector<vector<int>> dp;
    int lcs(int i, int j, string& s1, string& s2){
        if(i == -1 || j == -1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s1[i] == s2[j]) ans = 1 + lcs(i-1,j-1, s1,s2);
        else ans =  max(lcs(i-1,j, s1, s2), lcs(i, j-1, s1, s2));
        return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
        n = s.size();
        string s2 = string(s.rbegin(), s.rend());
        dp.assign(n, vector<int>(n, -1));
        return lcs(n-1, n-1, s, s2);
    }
};