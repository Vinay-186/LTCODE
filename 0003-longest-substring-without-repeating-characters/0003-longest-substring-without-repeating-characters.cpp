class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        map<char, int> chars;
        int i = 0, j = 1;
        chars[s[i]]++;
        int ans = 1;
        while(j < n){
            if(chars[s[j]] == 1) chars[s[i++]]--;
            else chars[s[j++]]++;
            ans = max(ans, j - i);
        }
        return ans;
    }
};