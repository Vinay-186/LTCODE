class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>> as(n, vector<int>(2,0));
        for(int i = 0; i < n; i++) as[i][0] = ages[i], as[i][1] = scores[i];
        sort(as.begin(), as.end());
        vector<int> dp(n);
        for(int i = 0; i < n; i++) dp[i] = as[i][1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(as[i][0] == as[j][0] || as[i][1] >= as[j][1]){
                    dp[i] = max(dp[i], as[i][1] + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};