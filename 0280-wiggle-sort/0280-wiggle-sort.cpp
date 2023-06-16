class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= n-2; i+=2){
            swap(nums[i], nums[i+1]);
        }
    }
};