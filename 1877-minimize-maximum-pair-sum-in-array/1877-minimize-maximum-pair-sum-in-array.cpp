class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0 , right = nums.size()-1, mini_MAX_SUM = 0;
        while(left < right) mini_MAX_SUM = max(mini_MAX_SUM, nums[left++] + nums[right--]);
        return mini_MAX_SUM;
    }
};