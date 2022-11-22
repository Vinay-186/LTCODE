class Solution {
public:
    int sz,n;
    vector<vector<int>> dp;
    int ns(int ind, int sum){
        if(sum > n) return 1e8;
        if(ind <= 0){
            if(sum == n){
                return 0;
            }
            return 1e8;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int include = 1 + ns(ind, sum + ind*ind);
        int exclude = ns(ind-1, sum);
        return dp[ind][sum] = min(include, exclude);
    }
    int numSquares(int n) {
       sz = pow(n, 0.5);
       this->n = n;
       dp.resize(sz+1, vector<int>(n+1,-1));
       return ns(sz,0);
    }
};