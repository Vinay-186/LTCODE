class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int l_x = 0, r_x = m-1;
        int l_y = 0, r_y = n-1;
        vector<int> ans;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        while(l_x <= r_x && l_y <= r_y){
            for(int i = l_y ; i <= r_y; i++){
                if(!vis[l_x][i])
                    ans.push_back(matrix[l_x][i]), vis[l_x][i]=1;
            }
            for(int i = l_x + 1; i <= r_x; i++){
                if(!vis[i][r_y])
                    ans.push_back(matrix[i][r_y]), vis[i][r_y]=1;
            }
            for(int i = r_y - 1; i >= l_y; i--){
                if(!vis[r_x][i])
                    ans.push_back(matrix[r_x][i]), vis[r_x][i]=1;
            }
            for(int i = r_x -1; i > l_x; i--){
                if(!vis[i][l_y])
                    ans.push_back(matrix[i][l_y]), vis[i][l_y]=1;
            }
            l_x++, l_y++;  
            r_x--, r_y--;
        }
        return ans;
    }
};

// m = 3, n = 4
// l_x = 0, l_y = 0, r_x = 2, r_y = 3;
// l_x = 1, l_y = 1, r_x = 1, r_y = 2;