class Solution {
public:
    int n;
    vector<int> dp;
    bool p(string& s, int i, int j){
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
    int mc(string& s, int ind){
        if(ind == n) return -1;
        if(dp[ind] != -1) return dp[ind];
        int mini = INT_MAX;
        for(int i = ind; i < n; i++){
            if(p(s, ind, i)){
                mini = min(mini, 1 + mc(s,i+1));
            }
        }
        return dp[ind] = mini;
    }
    int minCut(string s) {
        n = s.size();
        dp.resize(n, -1);
        return mc(s,0);
    }
};