class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        map<char, int> mp;
        int i = 0, j = 0;
        char c1 = s[i];
        char c2 = '$';
        int maxi = INT_MIN;
        mp[s[i]] = i;
        while(j < n){
            if(s[j] != c1){
                if(c2 == '$'){
                    c2 = s[j];
                }else if(s[j] != c2){
                   maxi = max(maxi, j - i);
                   int c1_end, c2_end;
                   c1_end = mp[c1];
                   c2_end = mp[c2];
                   if(c2_end < c1_end){
                       i = c2_end + 1;
                       c2 = s[j];
                   }else if(c1_end < c2_end){
                       i = c1_end + 1;
                       c1 = c2;
                       c2 = s[j];
                   }
                }
                mp[c2] = j;
            }else mp[c1] = j;
            j++;
        }
        return max(maxi, j-i);
    }
};