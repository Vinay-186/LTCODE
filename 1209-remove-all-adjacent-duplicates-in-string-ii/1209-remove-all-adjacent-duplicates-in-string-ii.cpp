class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<string, int>> b;
        b.push({s.substr(0,1), 1});
        for(int i = 1; i < n; i++){
            if(b.empty() || b.top().first[0] != s[i]){
                b.push({s.substr(i,1), 1});
            }else if(b.top().first[0] == s[i]){
                if(b.top().second == k-1){
                    b.pop();
                }else{
                    b.top().first += s[i];
                    b.top().second++;
                }
            }
        }
        string ans = "";
        while(!b.empty()){
            ans += b.top().first;
            b.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};