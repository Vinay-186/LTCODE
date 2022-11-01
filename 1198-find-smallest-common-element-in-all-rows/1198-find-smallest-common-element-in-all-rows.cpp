class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int, int> mp;
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[mat[i][j]]++;
                if(mp[mat[i][j]] == n) ans = min(ans,mat[i][j]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};