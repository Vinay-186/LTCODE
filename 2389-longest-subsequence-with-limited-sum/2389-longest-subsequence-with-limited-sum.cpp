class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> pref(n);
        partial_sum(nums.begin(), nums.end(), pref.begin());
        vector<int> ans;
        for(int& i : queries) ans.push_back(upper_bound(pref.begin(), pref.end(), i) - pref.begin());
        return ans;
    }
};