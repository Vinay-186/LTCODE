class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int num : nums) freq[num]++;
        int ans = 0;
        for(int num : freq) ans += ((num) * (num-1)) /2;
        return ans;
    }
};