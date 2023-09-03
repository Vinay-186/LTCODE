class Solution {
public:
    vector<int> dp;
    int extra(string& s, int idx, int n, set<string>& st){
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int use , dontUse;
        use = dontUse = 1e8;
        dontUse = 1 + extra(s, idx+1, n, st);
        for(int i = idx; i < n; i++){
            string subStr = s.substr(idx, i - idx + 1);
            if(st.find(subStr) == st.end()) continue;
            use = min(use, extra(s, i+1, n, st));
        }
        return dp[idx] = min(use, dontUse);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st;
        st.insert(dictionary.begin(), dictionary.end());
        int n = s.size();
        dp.assign(n, -1);
        return extra(s, 0, n, st);
    }
};