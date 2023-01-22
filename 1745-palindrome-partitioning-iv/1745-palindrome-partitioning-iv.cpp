class Solution {
public:
	bool checkPartitioning(string s) {
		int n = s.size();
		vector<vector<int>> p(n+1,vector<int> (n,1));
        for(int i = n-1 ; i >= 0; i--)for(int j = i+1; j < n; j++)p[i][j] = (s[i] == s[j])? p[i+1][j-1] : 0;
		for(int i=0;i<n;i++)for(int j=i+1;j<n-1;j++)if(p[0][i] && p[i+1][j] && p[j+1][n-1]) return true;
		return false;
	}
};