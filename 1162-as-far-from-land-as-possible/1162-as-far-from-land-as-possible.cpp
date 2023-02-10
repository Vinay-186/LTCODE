class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>> water, land;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) water.push_back({i,j});
                else land.push_back({i,j});
            }
        }
        if(water.empty() || land.empty()) return -1;
        int maxi = INT_MIN;
        for(auto& [x1, y1] : water){
            int mini = INT_MAX;
            for(auto& [x2, y2] : land) mini = min(mini, abs(x1-x2) + abs(y1-y2));
            maxi = max(maxi, mini);
        }
        return maxi;
    }
};