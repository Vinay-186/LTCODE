class Solution {
public:
    bool p(string & s, int l, int r){
        while(l <= r) if(s[l++] != s[r--]) return false;
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = -1;
        for(int ind = n-1; ind >= 0; ind--){
            int mini = INT_MAX;
            for(int i = ind; i <n ;i++) if(p(s,ind,i)) mini = min(mini,1+dp[i+1]);
            dp[ind] = mini;
        }        
        return dp[0];
    }
};