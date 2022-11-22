class Solution {
public:
    int numSquares(int n) {
       int m = 1e8;
       int sz = pow(n, 0.5);
       vector<int> prev(n+1, m), cur(n+1, m);
       prev[n] = 0;
       for(int i = 1; i <= sz; i++){
           for(int j = n; j >= 0; j--) cur[j] = min((j + i*i <= n)? 1 + cur[j+i*i] : m, prev[j]);
           prev = cur;
       }
       return prev[0];
    }
};