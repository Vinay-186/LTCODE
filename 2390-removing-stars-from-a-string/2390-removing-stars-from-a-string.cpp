class Solution {
public:
    string removeStars(string s) {
        bool star = false;
        string ans;
        int count = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '*') star = true, count++;
            else{
                if(star && count){
                    count--;
                    if(count == 0) star = false;
                    continue;
                }
                else ans += s[i];
            }
        }
        return string(ans.rbegin(), ans.rend());
    }
};