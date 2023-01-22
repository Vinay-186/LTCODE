class Solution {
public:
    vector<vector<string>> res;
    int n;
    bool p(string& temp){
        int i = 0,j = temp.size()-1;
        while(i < j) if(temp[i++] != temp[j--]) return false;
        return true;
    }
    void helper(string& s,int ind,vector<string>& ans){
        if(ind == n){
            res.push_back(ans);
            return ;    
        }
        string temp;
        for(int i = ind; i < n; i++){
            temp += s[i];
            if(p(temp)){
                ans.push_back(temp);
                helper(s,i+1,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string> ans;
        helper(s,0,ans);
        return res;
    }
};