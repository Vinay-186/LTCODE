class Solution {
public:
    bool isValid(string s) {
        map<char, char> mp = {{')', '('}, {']', '['}, {'}','{'}};
        stack<char> st;
        for(char c : s){
            if(st.empty() && mp.find(c) == mp.end() || mp.find(c) == mp.end()){
                st.push(c);
            }else{
                if(st.empty()) return false;
                if(mp[c] != st.top()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};