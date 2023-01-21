class Solution {
public:
    vector<string> res;
    int n;
    void helper(string& s, int ind, string ans, int cnt){
        if(cnt == 3){
            if( n-ind == 0 ||n - ind > 3 || (n - ind > 1 && s[ind] == '0') ||stoi(s.substr(ind)) > 255) return;
            else {
                res.push_back(ans + s.substr(ind));
                return;
            }
        }
        string temp;
        int sz = min(ind + 3, n);
        for(int i = ind; i < sz;i++){
            if(temp.size() == 1 && temp[0] == '0') break;
            temp += s[i];
            if(stoi(temp) > 255) continue;
            helper(s,i+1, ans + temp + '.', cnt + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        helper(s,0,"",0);
        return res;
    }
};