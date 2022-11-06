class Solution {
public:
    set<string> dict;
    int sz;
    vector<int> dp;
    bool w(string s,int ind){
        if(ind == sz) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind; i < sz; i++) if(dict.find(s.substr(ind, i-ind + 1)) != dict.end()) if(w(s,i+1)) return dp[ind] = true;
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& word) {
        dict.insert(word.begin(), word.end());
        sz = s.size();
        if(dict.find(s) != dict.end()) return true;
        dp.resize(sz,-1);
        return w(s,0);
    }
};