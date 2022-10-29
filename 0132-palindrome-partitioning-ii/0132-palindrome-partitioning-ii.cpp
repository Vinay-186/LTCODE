class Solution {
public:
    vector<vector<int>> mp;
    bool p(string & s, int l, int r){
        if(l >= r) return true;
        if(mp[l][r] != -1) return mp[l][r];
        if(s[l] == s[r]) return mp[l][r] = p(s,l+1,r-1);
        return mp[l][r] =false;
    }
    int minCut(string s) {
        int n = s.size();
        mp.resize(n, vector<int>(n,-1));
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