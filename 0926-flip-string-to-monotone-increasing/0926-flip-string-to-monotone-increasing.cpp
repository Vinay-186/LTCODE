class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int c0,c1,p0,p1;
        p0 = p1 = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0') c0 = p0 , c1 = 1 + p1;
            else c0 = min(1 + p0, p1), c1 = p1;
            p0 = c0;
            p1 = c1;
        }
        return p0;
    }
};