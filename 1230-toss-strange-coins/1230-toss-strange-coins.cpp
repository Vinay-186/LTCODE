class Solution {
public:
    int n;
    vector<vector<double>> dp;
    double probabilityOfHeads(vector<double>& prob, int target) {
       n = prob.size();
       dp.assign(n+1, vector<double>(target+1, 0));
       dp[n][0] = 1;
       for(int i = n-1; i >= 0; i--){
           for(int j = 0; j <= target; j++){
                double pick = (j != 0)? dp[i+1][j-1] * prob[i] : 0;
                double notpick = dp[i+1][j] * (1-prob[i]);
                dp[i][j] = pick + notpick;               
           }
       }
       return dp[0][target];
    }
};