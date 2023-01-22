class Solution {
public:
	vector<vector<int>> dp;
	bool p(string& s, int i, int j) {
		if (i >= j) return true;
		if (dp[i][j] != -1) return dp[i][j];
		if (s[i] == s[j]) return dp[i][j] = p(s, i + 1, j - 1);
		return dp[i][j] = false;
	}
	bool checkPartitioning(string s) {
		int n = s.size();
		dp.resize(n,vector<int> (n,-1));
		for(int i=0;i<n;i++)for(int j=i+1;j<n-1;j++)if(p(s,0,i) && p(s,i+1,j) && p(s,j+1,n-1)) return true;
		return false;
	}
};