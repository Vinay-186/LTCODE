class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char& c : s){
            if(c == '*'){
                st.pop();
            }else st.push(c);
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return string(ans.rbegin(), ans.rend());
    }
};