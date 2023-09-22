class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1;
        long long dp = 1;
        for(int i = 1; i <n; i++){
            if(prices[i] == prices[i-1] -1) dp++;
            else dp = 1;
            ans += dp;
        }
        return ans;
    }
};