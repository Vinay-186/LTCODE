class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26,0);
        int count = 0; 
        int n = s.size();
        int r = 0;
        while(r < n){
           if(freq[s[r] - 'a'] == 0) freq[s[r++]-'a']++;
           else{
               freq.assign(26,0);
               count++;
           }
        }
        return count+1;
    }
};