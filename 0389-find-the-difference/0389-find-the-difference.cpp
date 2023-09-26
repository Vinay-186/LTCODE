class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> s_freq(26,0);
        for(char c : s) s_freq[c-'a']++;
        for(char c : t){
            if(s_freq[c-'a'] == 0) return c;
            s_freq[c-'a']--;
        }
        return '-';
    }
};