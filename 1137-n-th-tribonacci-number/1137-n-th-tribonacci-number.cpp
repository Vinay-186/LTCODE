class Solution {
public:
    vector<int> dp;
    int t(int n){
        if(dp[n] != -1) return dp[n];
        return dp[n] = t(n-1) + t(n-2) + t(n-3); 
    }
    int tribonacci(int n) {
        dp.resize(38,-1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        return t(n);
    }
};