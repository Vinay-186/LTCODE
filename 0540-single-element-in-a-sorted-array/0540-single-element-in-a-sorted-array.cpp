class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0; 
        int high = n-1;
        while(low <= high){
            int mid = (low + high) >> 1;
            int val = nums[mid];
            if(mid-1 >= 0 && nums[mid-1] == nums[mid]){
                if((mid - low - 1) % 2 == 0){
                    low = mid + 1;
                }else{
                    high = mid-2;
                }
            }else if(mid + 1 < n && nums[mid] == nums[mid+1]){
                if((mid-low) % 2 == 0){
                    low = mid+2;
                }else{
                    high = mid-1;
                }
            }else{
                return nums[mid];
            }
        }
        return -1;
    }
};