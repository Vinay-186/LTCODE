class Solution {
public:
    set<vector<int>> res;
    int n;
    void helper(vector<int>& nums, int ind, vector<int>& ans){
        if(ind == n){
            if(ans.size() >= 2) res.insert(ans);
            return;
        }
        if(ans.empty() || nums[ind] >= ans.back()){
            ans.push_back(nums[ind]);
            helper(nums, ind+1, ans);
            ans.pop_back();
        }
        helper(nums, ind+1,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ans;
        n = nums.size();
        helper(nums, 0, ans);
        return vector(res.begin(),res.end());
    }
};