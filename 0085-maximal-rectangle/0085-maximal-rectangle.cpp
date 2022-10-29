class Solution {
public:
    int n, m;
    int area(vector<int>& histo){
        stack<int> b;
        int maxi = INT_MIN;
        for(int i = 0; i <= m;i++){
            while(!b.empty() && (i == m || histo[b.top()] >= histo[i])){
                int height = histo[b.top()];
                b.pop();
                int width;
                if(b.empty()) width = i;
                else width = i - b.top() - 1;
                maxi = max(maxi, width * height);
            }
            b.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<int> histo(m,0);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)if(matrix[i][j] == '0') histo[j] = 0;else histo[j]++;
            maxi = max(maxi, area(histo));
        }
        return maxi;
    }
};