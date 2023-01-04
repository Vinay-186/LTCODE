class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, vector<int>> mp;
        int n = s.size();
        int i = 0, j = 0;
        char c1 = s[i];
        char c2 = '$';
        int maxi = INT_MIN;
        mp[s[i]].push_back(i);
        while(j < n){
            if(s[j] != c1){
                if(c2 == '$'){
                    c2 = s[j];
                }else if(s[j] != c2){
                   maxi = max(maxi, j - i);
                   int c1_end, c2_end;
                   c1_end = mp[c1].back();
                   c2_end = mp[c2].back();
                   if(c2_end < c1_end){
                       i = c2_end + 1;
                       c2 = s[j];
                   }else if(c1_end < c2_end){
                       i = c1_end + 1;
                       c1 = c2;
                       c2 = s[j];
                   }
                }
                mp[c2].push_back(j);
            }else{
                mp[c1].push_back(j);
            }
            j++;
        }
        return max(maxi, j-i);
    }
};