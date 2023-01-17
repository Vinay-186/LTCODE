class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int mfmi(string& s,int ind, int prev){
        if(ind == n) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        return dp[ind][prev] = (prev == 0)? ((s[ind] == '0')? mfmi(s,ind+1,0) : min(1 + mfmi(s,ind+1,0),mfmi(s,ind+1,1))) : ((s[ind] == '0')? 1 + mfmi(s,ind+1,1) : mfmi(s,ind+1,1));
    }
    int minFlipsMonoIncr(string s) {
        n = s.size();
        dp.resize(n, vector<int>(2,-1));
        return mfmi(s,0,0);
    }
};