class Solution {
public:
    int n;
    vector<int> dp;
    int j(vector<int>& nums, int ind){
        if(ind >= n-1) return 0;
        if(nums[ind] == 0) return 1e8;
        if(dp[ind] != -1) return dp[ind];
        int mini = 1e8;
        for(int i = ind+nums[ind]; i >= ind+1; i--) mini = min(mini, 1 + j(nums, i));
        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
       n = nums.size();
       dp.resize(n,-1);
       return j(nums,0);
    }
};