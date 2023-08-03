class Solution {
public:
    bool safe(int i, int j, vector<vector<int>> positions){
        for(vector<int>& position : positions){
            if(i == position[0] || j == position[1]) return false;
            int x = abs(position[0] - i);
            int y = abs(position[1] - j);
            if(x == y) return false;
        }
        return true;
    }
    void helper(int i, int& n, int cnt,
                vector<vector<int>>& positions,
                vector<string>& ans, vector<vector<string>>& res)
    {
        if(i == n && cnt == n){
            res.push_back(ans);
            return;
        }
        for(int j = 0 ; j < n; j++){
            if(ans[i][j] == '.' && safe(i, j, positions)){
                positions.push_back({i,j});
                ans[i][j] = 'Q';
                helper(i+1, n,cnt+1, positions, ans, res);
                ans[i][j] = '.';
                positions.pop_back();
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> ans(n, s);
        vector<vector<string>> res;
        vector<vector<int>> positions;
        helper(0,n,0,positions, ans, res);
        return res;
    }
};