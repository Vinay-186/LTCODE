class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = accumulate(beans.begin(), beans.end(), 0ll);
        long long n = beans.size();
        long long mini = LONG_MAX;
        for(long long i = 0; i < n; i++){
            mini = min(mini, sum - (n-i) * beans[i] * 1ll);
        }
        return mini;
    }
};