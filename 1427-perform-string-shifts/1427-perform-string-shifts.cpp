class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left = 0;
        int n = s.size();
        for(vector<int>& i : shift) left += (i[0])? (-i[1]) : (+i[1]);
        left %= n;
        if(left == 0) return s;
        int idx = (left < 0)? n+left : left;
        return s.substr(idx) + s.substr(0,idx);
    }
};