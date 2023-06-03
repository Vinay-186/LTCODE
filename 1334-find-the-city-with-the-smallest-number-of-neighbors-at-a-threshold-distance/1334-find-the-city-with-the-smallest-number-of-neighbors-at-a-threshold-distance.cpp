class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e8));
        for(vector<int>& edge : edges){
            matrix[edge[0]][edge[1]] = edge[2];
            matrix[edge[1]][edge[0]] = edge[2];
        }
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        int mini = n;
        int final_ans = 0;
        for(int i = 0 ;i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(matrix[i][j] <= k) cnt++;
            }
            if(cnt <= mini){
                mini = cnt;
                final_ans = i;
            }
        }
        return final_ans;
    }
};