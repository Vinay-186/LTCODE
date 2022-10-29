class Solution {
public:
    int minCut(string a) {
        int n=a.size();
        int dp[n+2],i,j,k;
        for(i=0;i<=n;i++) dp[i] = i-1;
        for(i=0;i<n;i++){
            for(j=0;i-j>=0&&i+j<n&&a[j+i]==a[i-j];j++) dp[i+j+1]=min(dp[i+j+1],dp[i-j]+1);
            for(j=1;i-j+1>=0&&i+j<n&&a[j+i]==a[i-j+1];j++) dp[i+j+1]=min(dp[i+j+1],dp[i-j+1]+1);
        }
        return dp[n];
    }
};