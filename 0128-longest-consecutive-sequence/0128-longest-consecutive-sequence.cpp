class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> st;
        st.insert(nums.begin(), nums.end());
        int ans = 1;
        for(int num : nums){
            if(st.find(num-1) != st.end()) continue;
            int cnt = 1;
            while(st.find(++num) != st.end()) cnt++;
            ans = max(ans, cnt);
            cnt = 0;
        }
        return ans;
    }
};