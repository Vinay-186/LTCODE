class Solution {
public:
    int v(string s){
        int ans = 0;
        for(char& c : s) ans += int(c);
        return ans;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int> freq(26,0);
        int val = 0;
        for(char& i : s1) freq[i - 'a']++, val += int(i); 
        vector<int> temp = freq;
        for(int i = 0; i <= m-n; i++){ 
            string t = s2.substr(i, n);
            if(val == v(t)){ 
               bool found = true;
               for(char& c : t){
                   freq[c-'a']--; 
                   if(freq[c-'a'] < 0){
                       found = false;
                       break;
                   }
               }
               if(found) return true;
               freq = temp;
            }
        }
        return false;
    }
};