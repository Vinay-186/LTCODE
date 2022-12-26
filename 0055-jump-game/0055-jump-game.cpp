class Solution {
public:
    int n;
    vector<int> dp;
    bool cj(vector<int>& nums, int ind){
        if(ind >= n-1 || ind + nums[ind] >= n-1) return true;
        if(nums[ind] == 0) return false;
        if(dp[ind] != -1) return dp[ind];
        int m = nums[ind];
        bool var = false;
        for(int i = 1; i <= m;i++){
            if(cj(nums, ind + i)){
                var = true;
                break;
            }
        } 
        return dp[ind] = var;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,-1);
        return cj(nums, 0);
    }
};