class Solution {
public:
    void helper(vector<int>& nums, int idx, int& n, 
                int& target,int& sum,  vector<int>& curr, vector<vector<int>>& res)
    {
        if(sum == target)
            res.push_back(curr);
        for(int i = idx; i < n; i++){
            if(sum > target) continue;
            curr.push_back(nums[i]);
            sum += nums[i];
            helper(nums, i, n, target, sum, curr, res);
            sum -= nums[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> curr;
        vector<vector<int>> res;
        int sum = 0;
        helper(candidates, 0, n, target,sum,curr, res);
        return res;
    }
};