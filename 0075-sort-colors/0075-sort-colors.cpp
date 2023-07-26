class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_end, two_start;
        int n = nums.size();
        zero_end = 0;
        two_start = n-1;
        for(int i = 0; i < n; i++){
            if(nums[i] < 1 && i > zero_end){
                swap(nums[i], nums[zero_end++]);
                i--;
                continue;
            }
            if(nums[i] > 1 && i < two_start){
                swap(nums[i], nums[two_start--]);
                i--;
            }
        }
    }
};