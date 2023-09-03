class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st;
        st.insert(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            int use , dontUse;
            use = dontUse = 1e8;
            dontUse = 1 + dp[i+1];
            string subStr;
            for(int j = i; j < n; j++){
                subStr += s[j];
                if(st.find(subStr) == st.end()) continue;
                use = min(use, dp[j+1]);
            }
            dp[i] = min(use, dontUse);
        }
        return dp[0];
    }
};