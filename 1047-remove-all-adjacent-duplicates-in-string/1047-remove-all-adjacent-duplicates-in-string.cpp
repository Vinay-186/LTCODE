class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> b;
        b.push(s[0]);
        for(int i = 1; i < n; i++){
            if(b.empty() || b.top() != s[i]) b.push(s[i]);
            else if(b.top() == s[i]) b.pop();
        }
        string ans = "";
        while(!b.empty()){
            ans += b.top();
            b.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};