class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        if(abs(l1-l2) > 1) return false;
        int i = 0, j = 0;
        while(i < l1 && j < l2 && s[i] == t[j]) {
            i++,j++;
        }
        if(i == l1 && j == l2) return false;
        if(l1 > l2) return s.substr(i+1) == t.substr(j);
        if(l1 < l2) return s.substr(i) == t.substr(j+1);
        return s.substr(i+1) == t.substr(j+1);
    }
};