class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> b;
        int maxi = INT_MIN;
        for(int i = 0; i <= n; i++){
            while(!b.empty() && (i == n || heights[b.top()] >= heights[i])){
                int height = heights[b.top()];
                b.pop();
                int width ;
                if(b.empty()) width = i;
                else width = i - b.top() - 1;
                maxi = max(maxi,width*height);
            }
            b.push(i);
        }
        return maxi;
    }
};
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);