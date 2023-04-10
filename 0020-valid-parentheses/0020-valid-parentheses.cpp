class Solution {
public:
    bool isValid(string s) {
        map<char, char> mp = {{'[', ']'}, {'{', '}'}, {'(', ')'}};
        stack<char> st;
        for(char& c : s){
            if(mp.find(c) != mp.end()){
                st.push(c);
            }else{
                if(st.empty()) return false;
                if(mp[st.top()] != c) return false;
                else st.pop();
            }
        }
        return (!st.empty())? false : true;
    }
};