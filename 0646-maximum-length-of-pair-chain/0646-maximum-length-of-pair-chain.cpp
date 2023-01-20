class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        int n = p.size();
        vector<int> cur(n+1,0), prev(n+1,0);
        for(int i = n-1; i >= 0; i--){
            for(int j = n; j >= 0; j--){
                int pick,notpick;
                pick = notpick = INT_MIN;
                if(j == 0 || p[j-1][1] < p[i][0]) pick = 1 + prev[i+1];
                notpick = prev[j];
                cur[j] = max(pick,notpick);
            }
            prev = cur;
        }
        return prev[0];
    }
};