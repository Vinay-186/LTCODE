class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = n-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                int pick,notpick;
                pick = notpick = INT_MIN;
                if(j == 0 || p[j-1][1] < p[i][0]) pick = 1 + dp[i+1][i+1];
                notpick = dp[i+1][j];
                dp[i][j] = max(pick,notpick);
            }
        }
        return dp[0][0];
    }
};