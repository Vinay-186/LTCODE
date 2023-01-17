class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0 ; j <= 1; j++){
                if(j == 0){
                    if(s[i] == '0') dp[i][0] = dp[i+1][0];
                    else dp[i][0] = min(1 + dp[i+1][0], dp[i+1][1]);
                }else{
                    if(s[i] == '0') dp[i][1] = 1 + dp[i+1][1];
                    else dp[i][1] = dp[i+1][1];
                }
            }
        }
        return dp[0][0];
    }
};