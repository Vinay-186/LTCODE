class Solution {
private : 
    int lower_bound(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1;
        int index = nums.size();
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] >= target){
                r = mid-1;
                index = mid;
            }else{
                l = mid+1;
            }
        }
        return index;
    }
    
    int upper_bound(vector<int>& nums, int target){
        int l = 0, r = nums.size() -1;
        int index = nums.size();
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= target) l = mid+1;
            else r = mid-1, index = mid;
        }
        return index;
    }
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = upper_bound(nums, target);
        int count = last - first;
        return count > nums.size()/2;
    }
};