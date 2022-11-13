class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        for(int i = 0 ;i < s.length(); i++){
            if(s[i] != ' '){
                int start = i + 1;
                string str = "";
                str += s[i];
                while(start < s.length() && s[start] != ' '){
                    str += s[start];
                    start++;
                }
                words.push_back(str);
                i = start;
            }
        }
        string ans = "";
        int size = words.size();
        for(int i = size -1 ;i >= 1; i--){
            ans += words[i] + " ";
        }
        ans += words[0];
        return ans;
    }
};