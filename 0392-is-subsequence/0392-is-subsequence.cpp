class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        vector<int> prev(tSize+1, 1), cur(tSize + 1, 0);
        for(int i = 1; i <= sSize; i++){
            for(int j = 1; j <= tSize; j++){
                bool cond1 = (s[i-1] == t[j-1])? prev[j-1] : false;
                bool cond2 = cur[j-1];
                cur[j] = cond1 || cond2;
            }
            prev = cur;
        }
        return prev[tSize];
    }
};