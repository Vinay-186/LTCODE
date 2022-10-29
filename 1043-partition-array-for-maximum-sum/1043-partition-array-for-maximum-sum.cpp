class Solution {
public:
    int k ;
    int n ;
    vector<int> dp;
    int msap(vector<int>& arr, int ind){
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ans = INT_MIN;
        for(int j = ind; j < ind + k && j < n; j++){
            int maxi = *max_element(arr.begin() + ind,arr.begin() + j+1);
            int cost = maxi * (j - ind + 1) + msap(arr,j+1);
            ans = max(ans, cost);
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k = k;
        n = arr.size();
        dp.resize(n,-1);
        return msap(arr,0);
    }
};