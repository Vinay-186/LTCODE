class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        set<string> dict;
        dict.insert(word.begin(), word.end());
        int sz = s.size();
        if(dict.find(s) != dict.end()) return true;
        vector<int> dp(sz+1,0);
        dp[sz] = 1;
        for(int i = sz - 1; i >= 0; i--)for(int j = i; j < sz; j++)if(dict.find(s.substr(i,j-i+1)) != dict.end())if(dp[j+1] == 1) dp[i] = 1;
        return dp[0];
    }
};