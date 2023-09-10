class Solution {
public:
    int find_first_idx(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r-l)/2;
            int num = nums[mid];
            if(num < target){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        if(r == 0 && nums[r] == target) return r;
        if(r == n-1 && nums[r] == target) return r;
        return (r == 0 || r == n-1)?  -1 : r;
    }
    
    int find_last_idx(vector<int>& nums, int target){
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r - l)/2;
            int num = nums[mid];
            if(num <= target){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return r;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        if(n == 1 && nums[0] == target) return {0,0}; 
        int first_occ = find_first_idx(nums, target);
        if(first_occ == -1 || nums[first_occ] != target) return {-1,-1};
        int last_occ = find_last_idx(nums, target);
        if(nums[last_occ] == target) return {first_occ, last_occ};
        return {first_occ, last_occ-1};
    }
};