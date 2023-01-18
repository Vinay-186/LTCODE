class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int n = nums.size();
       int cmax = 0, cmin = 0, sum = 0, maxs = nums[0], mins=nums[0];
        for(int i = 0 ;i < n; i++){
            cmax = max(nums[i], cmax + nums[i]);
            maxs = max(maxs, cmax);
            cmin = min(nums[i], cmin + nums[i]);
            mins = min(cmin, mins);
            sum += nums[i];
        }
        return (sum == mins)? maxs : max(maxs, sum - mins);
    }
};