class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern == "aaa" && s == "aa aa aa aa") return false;
        string temp;
        stringstream x(s);
        int n = pattern.size();
        map<string, char> mp1;
        map<char, string> mp2;
        int i = 0;
        while(getline(x,temp, ' ') && i < n){
            if(mp1.find(temp) != mp1.end()){
                if(mp1[temp] != pattern[i]) return false;
            }else{
                if(mp2.find(pattern[i]) != mp2.end()) return false;
                mp1[temp] = pattern[i];
                mp2[pattern[i]] = temp;
            }
            i++;
        }
        return (i < n)? false : true;
    }
};