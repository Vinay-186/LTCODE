class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = n * n; 
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] != grid[j][k]){
                        count--;
                        break;
                    }
                }
            }
        }
        return count;
    }
};