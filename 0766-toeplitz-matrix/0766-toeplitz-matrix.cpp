class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) for(int k = i+1, j = 1 ; k < n && j < m; k++,j++) if(matrix[k][j] != matrix[k-1][j-1]) return false;
        for(int j = 1; j < m; j++) for(int i = 1 , k = j+1; i < n && k < m ; i++,k++) if(matrix[i-1][k-1] != matrix[i][k]) return false;
        return true;
    }
};