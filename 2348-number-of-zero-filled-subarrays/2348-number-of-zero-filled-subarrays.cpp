class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        for (int& i : nums) {
            if (i == 0)
                count++;
            else
                count = 0;
            ans += count;
        }
        return ans;
    }
};