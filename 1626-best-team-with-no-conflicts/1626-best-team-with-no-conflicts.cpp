class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<int> cur(n+1,0), prev(n+1,0);
        vector<vector<int>> as(n, vector<int>(2,0));
        for(int i = 0; i < n; i++) as[i][0] = ages[i], as[i][1] = scores[i];
        sort(as.begin(), as.end());
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int p,np;
                p = np = INT_MIN;
                if(j == 0 || as[i][0] == as[j-1][0] || as[i][1] >= as[j-1][1]) p = as[i][1] + prev[i+1];
                np = prev[j];
                cur[j] = max(p,np);
            }
            prev = cur;
        }
        return prev[0];
    }
};