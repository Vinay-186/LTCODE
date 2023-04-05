class Solution {
public:
    int n;
    set<string> check;
    void permute(string& s, queue<pair<string, int>>& q, int lev){
        for(int i = 0; i < n; i++){
            for(char c = 'a'; c <= 'z'; c++){
                if(s[i] == c) continue;
                string lastpart = (i+1 < n)? s.substr(i+1) : "";
                string temp = s.substr(0,i) + c + lastpart;
                set<string>::iterator iter = check.find(temp);
                if(iter != check.end()){
                    q.push({temp, lev+1});
                    check.erase(iter);
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = beginWord.size();
        check.insert(wordList.begin(), wordList.end());
        if(check.find(beginWord) != check.end()) check.erase(check.find(beginWord));
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [node, lev] = q.front();
            q.pop();
            if(node == endWord) return lev;
            permute(node, q, lev);
        }
        return 0;
    }
};