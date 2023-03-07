class Solution {
public:
    bool ok(int len, int& n, vector<int>& pref,int& target){
        int i = 0, j = len;
        while(j <= n) if(pref[j++] - pref[i++] >= target) return true;
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1,0);
        partial_sum(nums.begin(), nums.end(), pref.begin() + 1);
        int l = 1;
        int r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            if(ok(mid, n, pref,target)) r = mid;
            else l = mid + 1;
        }
        if(l == n && pref[l] < target) return 0;
        return l;
    }
};