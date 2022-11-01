class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int l = 0;
        int r = 0;
        int zero = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r] == 0)zero++;
            while (zero == 2) {
                if (nums[l] == 0) zero--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};