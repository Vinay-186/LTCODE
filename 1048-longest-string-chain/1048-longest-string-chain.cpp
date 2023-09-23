class Solution {
public:
    vector<int> dp;
    int longChain(vector<string>& words, int idx, map<string, int>& mp){
        if(dp[idx] != -1) return dp[idx];
        int maxi = 1; 
        string curr = words[idx];
        int sz = curr.size();
        for(int i = 0; i < sz; i++){
            string part1 = (i == 0)? "" : curr.substr(0, i);
            string part2 = (i+1 < sz)? curr.substr(i+1) : "";
            if(mp.find(part1 + part2)==mp.end()) continue;
            maxi = max(maxi, 1+longChain(words, mp[part1+part2], mp));
        }
        return dp[idx] = maxi;
    }
    int longestStrChain(vector<string>& words) {
        map<string,int> mp;
        for(int i = 0; i < words.size(); i++) mp[words[i]] = i;
        dp.assign(words.size(), -1);
        int maxi = 0;
        for(int i = words.size() -1; i >= 0; i--){
            maxi = max(maxi, (dp[i] != -1)? dp[i] : longChain(words, i, mp));
        }
        return maxi;
    }
};