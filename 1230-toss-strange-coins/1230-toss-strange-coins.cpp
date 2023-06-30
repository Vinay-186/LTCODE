class Solution {
public:
    int n;
    vector<vector<double>> dp;
    double fp(vector<double>& prob,int ind, int target){
        if(target < 0) return 0;
        if(ind == n) return target == 0? 1 : 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        double pick = fp(prob, ind+1, target-1) * prob[ind];
        double notpick = fp(prob, ind+1, target) * (1-prob[ind]);
        return dp[ind][target] = pick + notpick;
    }
    double probabilityOfHeads(vector<double>& prob, int target) {
       n = prob.size();
       dp.assign(n, vector<double>(target+1, -1));
       return fp(prob, 0, target);
    }
};