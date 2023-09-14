class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1 == s2) return true;
        int n = s1.size();
        vector<int> even_freq(26,0), odd_freq(26,0);
        for(int i = 0; i < n; i++){
            if(i % 2) odd_freq[s1[i] - 'a']++, odd_freq[s2[i] - 'a']--;
            else even_freq[s1[i] - 'a']++, even_freq[s2[i] - 'a']--;
        }
        for(int i : even_freq) if(i != 0) return false;
        for(int i : odd_freq) if(i != 0) return false;
        return true;
    }
};