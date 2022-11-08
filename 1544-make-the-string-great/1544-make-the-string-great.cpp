class Solution {
public:
    string makeGood(string s) {
        if(s.size() == 1) return s;
        map<char,char> mp;
        for(char c = 'a'; c <= 'z'; c++) mp[c] = toupper(c) , mp[toupper(c)] = c;
        for(int i = 0; i <= s.length() - 2; i++){
            if(s.length() == 0 || s.length() == 1) break;
            if(s[i+1] == mp[s[i]]){
                s.erase(s.begin()+i,s.begin()+i+2);
                if(i == 0) i--;
                else i-=2;
            }
        }
        return s;
    }
};