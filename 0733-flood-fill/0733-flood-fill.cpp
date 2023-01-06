class Solution {
public:
    int m, n, color, temp;
    vector<vector<int>> seen;
    void helper(vector<vector<int>>& img, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || seen[i][j] == 1) return;
        img[i][j] = color;
        seen[i][j] = 1;
        if(i-1 >= 0 && img[i-1][j] == temp) helper(img, i-1,j);
        if(i+1 < n && img[i+1][j] == temp) helper(img, i+1,j);
        if(j-1 >= 0 && img[i][j-1]== temp) helper(img, i, j-1);
        if(j+1 < m && img[i][j+1] == temp) helper(img, i, j+1);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        this->color = color;
        n = image.size();
        m = image[0].size();
        seen.resize(n,vector<int>(m,0));
        temp = image[sr][sc];
        helper(image, sr,sc);
        return image;
    }
};