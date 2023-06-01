class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        st.insert(wordList.begin(), wordList.end());
        set<string>:: iterator iter = st.find(beginWord);
        if(iter != st.end()){
            st.erase(iter);
        }
        queue<pair<string,int>> q;
        q.push({beginWord, 1});        
        while(!q.empty()){
            auto [node, lvl] = q.front();
            q.pop();
            if(node == endWord){
                return lvl;
            }
            for(int i = 0; i < node.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    if(node[i] == c) continue;
                    string temp = node.substr(0, i) + c + node.substr(i+1);
                    iter = st.find(temp);
                    if(iter != st.end()){
                        q.push({temp, lvl+1});
                        st.erase(iter);
                    }
                }
            }
        }
        return 0;
    }
};