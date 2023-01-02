class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1) return true;
        set<char> caps, lows;
        for(char c = 'A'; c <= 'Z'; c++) caps.insert(c);
        for(char c = 'a'; c <= 'z'; c++) lows.insert(c);
        string temp;
        if(lows.find(word[0]) != lows.end()){
            temp = word.substr(1);
            for(char& c : temp){
                if(caps.find(c) != caps.end()) return false;
            }
        }else if(caps.find(word[1]) != caps.end()){
            if(n > 2) temp = word.substr(2);
            else temp = "";
            for(char& c : temp){
                if(lows.find(c) != lows.end()) return false;
            }
        }else{
            if(n > 2) temp = word.substr(2);
            else temp = "";
            for(char& c : temp){
                if(caps.find(c) != caps.end()) return false;
            }
        }
        return true;
    }
};