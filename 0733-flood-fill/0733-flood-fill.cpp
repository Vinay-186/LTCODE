class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int temp = image[sr][sc];
        vector<vector<int>> seen(n, vector<int>(m,0));
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            image[i][j] = color;
            seen[i][j] = 1;
            if(i-1 >= 0 && seen[i-1][j] != 1 && image[i-1][j] == temp) q.push({i-1,j});
            if(i+1 < n && seen[i+1][j] != 1 && image[i+1][j] == temp) q.push({i+1,j});
            if(j-1 >= 0 && seen[i][j-1] != 1 && image[i][j-1] == temp) q.push({i,j-1});
            if(j+1 < m && seen[i][j+1] != 1 && image[i][j+1] == temp) q.push({i,j+1});
        }
        return image;
    }
};