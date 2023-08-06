class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxVal - minVal + 1);
        for(int num : nums) cnt[num- minVal]++;
        int remain = k;
        for(int num = cnt.size() -1; num >= 0; num--){
            remain -= cnt[num];
            if(remain <= 0){
                return num + minVal;
            }
        }
        return -1;
    }
};