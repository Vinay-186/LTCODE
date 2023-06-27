class Solution {
public:
    int n;
    map<int,vector<int>> mp;
    vector<vector<int>> dp;
    int helper(vector<int>& nums,int ind, int d){
        if(ind == n) return 0;
        if(dp[ind][d + 500] != -1) return dp[ind][d+500];
        int maxi = 0;
        if(d == 501){
            for(int i = ind + 1; i < n; i++){
                int pick = 1 + helper(nums,i, nums[i] - nums[ind]);
                maxi = max(maxi,pick);
            }
            maxi = max(maxi,helper(nums, ind+1, d));
        }else{
            int new_elem = nums[ind] + d;
            if(mp.find(new_elem) != mp.end()){
                auto iter = upper_bound(mp[new_elem].begin(), mp[new_elem].end(), ind);
                for(auto j = iter; j != mp[new_elem].end(); j++){
                    maxi = max(maxi, 1 + helper(nums, *j, d));
                }
            }
        }
        return dp[ind][d+500] = maxi;
    }
    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(1002,-1));
        if(n <= 2) return n;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        return 1 + helper(nums, 0, 501);
    }
};