class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i; j++){
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
        
    }
};


/*
1,2

11, 9, 1, 5
10, 8 , 4, 2
7, 6, 3, 13
16, 12, 14, 15


0,0 => 2,2  i=0, j=0  => i1 = n-j-1, j1 = n-i-1
0,1 => 1,2  i=0, j=1  => i1 = n-j-1, j1 = n-i-1
1,0 => 2,1  i=1, j=0  => i1 = n-j-1, j1 = n-i-1


*/