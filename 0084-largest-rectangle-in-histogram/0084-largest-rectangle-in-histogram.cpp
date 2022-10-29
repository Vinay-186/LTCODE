class Solution {
public:
    int n;
    vector<int> left (vector<int>& h){
        stack<int> b;
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            while(!b.empty() && h[i] <= h[b.top()]) b.pop();
            res[i] = (!b.empty())? b.top()+1 : 0;
            b.push(i);
        }
        return res;
    }
    vector<int> right(vector<int>& h){
        stack<int> b;
        vector<int> res(n);
        for(int i = n-1; i >= 0; i--){
            while(!b.empty() && h[i] <= h[b.top()]) b.pop();
            res[i] = (!b.empty())? b.top()-1 : n-1;
            b.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        vector<int> l = left(heights);
        vector<int> r = right(heights);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) maxi = max(maxi, heights[i] * (r[i] - l[i] + 1));
        return maxi;
    }
};