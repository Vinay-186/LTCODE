class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev = -1, cur = -1, n = nums.size(), maxi = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]) continue;
            cur = i;
            maxi = max(maxi, cur - prev -1);
            prev = cur;
        }
        if(cur == -1) return n;
        if(prev == cur) cur = n;
        return max(maxi, cur - prev -1);
    }
};