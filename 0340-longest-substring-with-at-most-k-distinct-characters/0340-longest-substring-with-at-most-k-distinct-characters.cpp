class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if(n * k == 0) return 0;
        map<char, int> mp;
        int l = 0,r = 0;
        int maxi = 1;
        while(r < n){
            mp[s[r]] = r;
            r++;
            if(mp.size() == k+1){
                int del = INT_MAX;
                for(auto& i : mp){
                    del = min(del, i.second);
                }
                mp.erase(s[del]);
                l = del + 1;
            }
            maxi = max(maxi, r - l );
        }
        return maxi;
    }
};