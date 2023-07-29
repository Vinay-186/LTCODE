class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n+1, 0);
        vector<int> cur(n+1, 0);
        cur[n-1] = 1;
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i == m-1 && j == n-1) continue;
                int down = prev[j];
                int right = cur[j+1];
                cur[j] = down + right;
            }
            prev = cur;
        }
        return cur[0];
    }
};