class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int l_x = 0, r_x = m-1;
        int l_y = 0, r_y = n-1;
        vector<int> ans;
        while(ans.size() < m * n){
            for(int i = l_y ; i <= r_y; i++){
                ans.push_back(matrix[l_x][i]);
            }
            for(int i = l_x + 1; i <= r_x; i++){
                ans.push_back(matrix[i][r_y]);
            }
            if(l_x != r_x){
                for(int i = r_y - 1; i >= l_y; i--){
                   ans.push_back(matrix[r_x][i]);
                }
            }
            if(l_y != r_y){
                for(int i = r_x -1; i > l_x; i--){
                   ans.push_back(matrix[i][l_y]);
                }
            }
            l_x++, l_y++;  
            r_x--, r_y--;
        }
        return ans;
    }
};