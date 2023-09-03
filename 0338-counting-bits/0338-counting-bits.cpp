class Solution {
public:
    int binary(int num,vector<int>& dp){
        int cnt = 0;
        while(num != 0){
            if(dp[num] != -1){
                cnt += dp[num];
                break;
            }
            if(num % 2 == 1) cnt++;
            num /= 2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> dp(n+1, -1);
        for(int i = 0; i <= n; i++){
            dp[i] = binary(i, dp);
        }
        return dp;
    }
};