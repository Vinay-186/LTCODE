class Solution {
public:
    void helper(int idx, int n,string& digits,
                vector<vector<char>>& words, string s, vector<string>& ans){
        if(idx == n){
            ans.push_back(s);
            return;
        }
        for(char c : words[stoi(digits.substr(idx, 1))]){
            helper(idx+1, n, digits, words, s + c, ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        vector<string> ans;
        vector<vector<char>> words(10);
        char c = 'a';
        for(int i = 2; i < 10; i++){
            int cnt = 0;
            if(i != 7 && i != 9){
                while(cnt < 3){
                    words[i].push_back(c++);
                    cnt++;
                }                
            }else{
                while(cnt < 4){
                    words[i].push_back(c++);
                    cnt++;
                }
            }
        }
        helper(0, n, digits, words, "", ans);
        return ans;
        
    }
};