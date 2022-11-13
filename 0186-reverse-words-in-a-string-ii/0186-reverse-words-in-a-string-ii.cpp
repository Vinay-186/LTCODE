class Solution {
public:
    void rev(vector<char>& s, int i , int j){
        while(i < j) swap(s[i++], s[j--]);
    }
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        for(int t = 0; t < n; t++){
            if(s[t] != ' '){
                int i = t;
                int j = t+1;
                while(j < n && s[j] != ' '){
                    j++;
                }
                rev(s,i,j-1);
                t = j;
            }
        }
    }
};