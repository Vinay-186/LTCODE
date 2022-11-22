class Solution {
public:
    int n;
    vector<int> dp;
    bool cj(vector<int>& nums, int ind){
        if(ind >= n - 1) return true;
        if(dp[ind] != -1) return dp[ind];
        bool f = false;
        for(int i = nums[ind]; i >= 1; i--){
            if(f == true) break;
            f = cj(nums,ind+i);
        }
        return dp[ind] = f;
    }
    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, -1);
        return cj(nums, 0);
    }
};