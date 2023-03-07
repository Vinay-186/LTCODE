class Solution {
public:
    int findPeak(vector<int>& nums){
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if(r - l == 1) return (nums[l] > nums[r])? l : r;
            int mid = (l + r) / 2;
            if (nums[mid] > nums[l]) l = mid;
            else r = mid-1;
        }
        return l;
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        if(nums.back() > nums[0]) return nums[0];
        return nums[findPeak(nums) + 1];
    }
};