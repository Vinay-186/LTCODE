#define ll long long

class Solution {
public:
    
    bool f(int mid, vector<vector<int>>& composition, 
           vector<int>& stock, vector<int>& cost, int budget, int n, int k)
    {
        ll minCost = INT_MAX;
        for(int i = 0; i < k; i++){
            ll curcost = 0;
            for(int j = 0; j < n; j++){
                ll curelem = 1ll * mid * composition[i][j];
                if(stock[j] >= curelem) continue;
                else{
                    curcost += (curelem-stock[j]) * cost[j];
                }
            }
            minCost = min(minCost, curcost);
        }
        return minCost <= budget;
    }
    
    
    int maxNumberOfAlloys(int n, int k, int budget, 
                          vector<vector<int>>& composition, 
                          vector<int>& stock, vector<int>& cost) 
    {
        int l = 0, h = 1e9, ans = 0;
        while(l <= h){
            int mid = (l + h) >> 1;
            if(f(mid, composition, stock, cost, budget, n, k)){
                l = mid + 1;
                ans = mid;
            }else{
                h = mid - 1;
            }
        }
        return ans;
    }
};