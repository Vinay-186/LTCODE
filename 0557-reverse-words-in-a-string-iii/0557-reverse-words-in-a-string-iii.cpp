class Solution {
public:
    string reverseWords(string s) {
        stringstream x(s);
        string temp;
        string ans;
        while(getline(x, temp, ' ')){
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
        }
        return string(ans.begin(), --ans.end());
    }
};