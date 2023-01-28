class Solution {
public:
    set<string> st;
    vector<int> dp;
    int n;
    bool sub(string& s, int ind){
        if(ind == n) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i = ind; i < n; i++){
            string temp = s.substr(ind, i - ind + 1);
            if(s != temp && st.find(temp) != st.end()){
                if(sub(s,i+1)) return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& w) {
        st.insert(w.begin(), w.end());
        vector<string> ans;
        for(string& i : w){
            n = i.size();
            dp.assign(n, -1);
            if(sub(i,0)) ans.push_back(i);
        }
        return ans;
    }
};