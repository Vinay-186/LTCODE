class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int flc(vector<vector<int>>& p, int ind,int prev){
        if(ind == n) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        int pick, notpick;
        pick = notpick = INT_MIN;
        if(prev == 0 || p[prev-1][1] < p[ind][0]){
            pick = 1 + flc(p,ind+1,ind+1);
        }
        notpick = flc(p,ind+1,prev);
        return dp[ind][prev] = max(pick,notpick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        n = pairs.size();
        dp.resize(n,vector<int>(n,-1));
        return flc(pairs,0,0);
    }
};