class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_all = 0, n = nums.size();
        for(int i = 0; i <= n; i++) xor_all ^= i;
        for(int num : nums) xor_all ^= num;
        return xor_all;
    }
};