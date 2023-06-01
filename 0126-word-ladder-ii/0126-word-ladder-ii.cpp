class Solution {
public:
    map<string,int> find_lvl(string beginWord, string endWord, vector<string>& wordList){
        set<string> st;
        map<string, int> mp;
        st.insert(wordList.begin(), wordList.end());
        set<string> :: iterator iter = st.find(beginWord);
        if(iter != st.end()) st.erase(iter);
        queue< pair<string, int>> q;
        q.push({beginWord, 0});
        while(!q.empty()){
            auto [node, lvl] = q.front();
            q.pop();
            mp[node] = lvl;
            for(int i = 0; i < node.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    if(node[i] == c) continue;
                    string temp = node.substr(0,i) + c + node.substr(i+1);
                    iter = st.find(temp);
                    if(iter != st.end()){
                        q.push({temp, lvl+1});
                        st.erase(iter);
                    }
                }
            }
        }
        return mp;
    }
    void dfs(string cur, string& beginWord,vector<string>& ans, vector<vector<string>>& res, 
             map<string,int>& mp){
        if(cur == beginWord){
            vector<string> ans1 = ans;
            ans1.push_back(beginWord);
            reverse(ans1.begin(), ans1.end());
            res.push_back(ans1);
            return;
        }
        int lvl = mp[cur];
        if(lvl == -1) return;
        ans.push_back(cur);
        for(int i = 0; i < cur.size(); i++){
            for(char c = 'a'; c <= 'z'; c++){
                if(c == cur[i]) continue;
                string temp = cur.substr(0, i) + c + cur.substr(i+1);
                if(mp.find(temp) != mp.end()){
                    int temp_lvl = mp[temp];
                    if(temp_lvl < lvl){
                        dfs(temp, beginWord, ans, res, mp);
                    }
                }
            }
        }
        ans.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, 
                                       vector<string>& wordList) {
        map<string,int> mp = find_lvl(beginWord, endWord, wordList);
        if(mp.find(endWord) == mp.end()) return {};
        for(string& s : wordList){
            if(mp.find(s) == mp.end()) mp[s] = -1;
        }
        vector<string> ans;
        vector<vector<string>> res;
        dfs(endWord, beginWord,ans , res, mp);
        return res;
    }
};