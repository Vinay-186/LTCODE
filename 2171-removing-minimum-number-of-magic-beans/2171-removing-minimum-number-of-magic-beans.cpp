class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        vector<long long> pref(n, 0);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += (long long) beans[i];
            pref[i] = sum;
        }
        vector<long long> diff(n, 0);
        for(int i = 0; i < n; i++){
            long long part1 = pref[n-1] - pref[i];
            long long part2 = (long long)(n - i - 1) * (long long)(beans[i]);
            diff[i] = part1 - part2;
        }
        long long mini = diff[0];
        for(int i = 1; i < n; i++){
            long long element = pref[i-1] + diff[i];
            mini = min(mini,element);
        }
        return mini;
    }
};
