class Solution {
public:
    bool a(string& s1, string& s2){
        if(s1.length() != s2.length()) return false;
        vector<int> freq(26,0);
        for(char& c : s1) freq[c - 'a']++;
        for(char& c : s2) freq[c - 'a']--;
        for(int i = 0; i <= 25; i++) if(freq[i] < 0) return false;
        return true;
    }
    bool isAnagram(string s, string t) {
        return a(s,t);
    }
};