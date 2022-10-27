class Solution {
public:
    map<char,char> ts,st;
    int n;
    bool helper(string& s, string& t, int i){
        if(i == n) return true;
        if(ts.find(t[i]) != ts.end() && ts[t[i]] != s[i]) return false;
        else ts[t[i]] = s[i];
        if(st.find(s[i]) != st.end() && st[s[i]] != t[i]) return false;
        else st[s[i]] = t[i];
        return helper(s,t,i+1);
    }
    bool isIsomorphic(string s, string t) {
        n = s.size();
        return helper(s,t,0);
    }
};