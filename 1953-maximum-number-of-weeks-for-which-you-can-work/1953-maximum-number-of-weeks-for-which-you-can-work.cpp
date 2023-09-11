class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int maxi = *max_element(milestones.begin(), milestones.end());
        long long sum = accumulate(milestones.begin(), milestones.end(), 0ll);
        long long rest = sum -maxi;
        return min(2* rest + 1, sum);
    }
};