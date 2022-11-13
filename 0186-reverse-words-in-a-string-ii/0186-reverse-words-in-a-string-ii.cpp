class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        for(int t = 0; t < n; t++){
            if(s[t] != ' '){
                int i = t;
                int j = t+1;
                while(j < n && s[j] != ' ') j++;
                reverse(s.begin() + i, s.begin() + j);
                t = j;
            }
        }
    }
};