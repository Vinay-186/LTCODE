class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < n -1 ) return -1;
        vector<int> indeg(n+1, 0), outdeg(n+1,0);
        for(vector<int>& i : trust) outdeg[i[0]]++,indeg[i[1]]++;
        for(int i = 1; i <= n; i++) if(indeg[i] == n-1 && outdeg[i] == 0) return i;
        return -1;
    }
};