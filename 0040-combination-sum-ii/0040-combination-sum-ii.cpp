class Solution {
public:
    void helper(vector<int>& nums, int idx, int& n, int& target,
                int& sum, vector<int>& curr, vector<vector<int>>& res)
    {
        if(sum == target){
            res.push_back(curr);
        }
        for(int i = idx; i< n; i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            if(sum > target) continue;
            sum += nums[i];
            curr.push_back(nums[i]);
            helper(nums, i+1, n, target, sum, curr, res);
            curr.pop_back();
            sum -= nums[i];
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> res;
        int sum = 0;
        helper(candidates, 0, n, target, sum, curr, res);
        return res;
    }
};