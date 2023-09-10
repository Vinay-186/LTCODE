class Solution {
public:
    void helper(string s, int cnt, vector<string>& ans, int n){
        if(cnt > n) return;
        if(n == 0){
            if(cnt == 0) ans.push_back(s);
            return;
        }
        helper(s + '(', cnt +1, ans, n);
        if(cnt > 0) helper(s + ')', cnt-1, ans, n-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        int cnt = 1;
        helper(s, cnt, ans, n);
        return ans;
    }
};