class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int bts(vector<vector<int>>& as, int ind, int prev){
        if(ind == n) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        int pick, notpick;
        pick = notpick = INT_MIN;
        if(prev == 0 || as[ind][0] == as[prev-1][0] || as[ind][1] >= as[prev-1][1]){
            pick = as[ind][1] + bts(as,ind+1, ind+1);
        }
        notpick = bts(as,ind+1,prev);
        return dp[ind][prev] = max(pick,notpick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = ages.size();
        dp.resize(n,vector<int>(n,-1));
        vector<vector<int>> as(n, vector<int>(2,0));
        for(int i = 0; i < n; i++) as[i][0] = ages[i], as[i][1] = scores[i];
        sort(as.begin(), as.end());
        return bts(as,0,0);
    }
};