class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r){
        if(l > r) return -1;
        int mid = l + (r - l)/2;
        if(nums[mid] > target) return bs(nums,target,l,mid-1);
        else if(nums[mid] < target) return bs(nums, target,mid+1, r);
        return mid;
    }
    int ls(vector<int>& nums, int target, int l, int r){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= target) l = mid+1;
            else if(nums[mid] > target) r = mid-1;
        }
        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int val = bs(nums, target, 0,n-1);
        return (val == -1)? ls(nums,target,0,n-1) : val;
    }
};