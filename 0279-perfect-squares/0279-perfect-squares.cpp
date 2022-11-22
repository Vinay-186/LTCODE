class Solution {
public:
    int numSquares(int n) {
       int sz = pow(n, 0.5);
       vector<int> prev(n+1, 1e8), cur(n+1, 1e8);
       prev[n] = 0;
       for(int i = 1; i <= sz; i++){
           for(int j = n; j >= 0; j--){
               int include = 1e8;
               if(j + i*i <= n)include = 1 + cur[j+i*i];
               int exclude = prev[j];
               cur[j] = min(include, exclude);
           }
           prev = cur;
       }
       return prev[0];
    }
};