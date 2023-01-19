class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mod(k,0);
        mod[0] = 1;
        int p = 0, res = 0;
        for(int& i : nums){
            p = (p + i) % k + k;
            res += mod[p % k];
            mod[p % k]++;
        }
        return res;
    }
};