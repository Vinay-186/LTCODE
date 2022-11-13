class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int idx = n - k;
        vector<int> ans;
        ans.insert(ans.end(), nums.begin() + idx, nums.end());
        ans.insert(ans.end(), nums.begin(), nums.begin() + idx);
        nums = ans;
    }
};