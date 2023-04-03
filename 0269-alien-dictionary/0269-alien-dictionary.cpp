class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, vector<char>> adj;
        map<char, int> indeg;
        int n = words.size();
        for(string& i : words){
            for(char& c : i){
                indeg[c] = 0;
                adj[c] = {};
            }
        }
        for(int i = 0; i < n-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            if(w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) return "";
            for(int j = 0; j < min(w1.size(), w2.size()); j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    indeg[w2[j]]++;
                    break;
                }
            }
        }
        string ans;
        queue<char> q;
        for(auto i : indeg){
            if(i.second == 0) q.push(i.first);
        }
        while(!q.empty()){
            char node = q.front();
            q.pop();
            ans += node;
            for(char& c : adj[node]){
                if(--indeg[c] == 0) q.push(c);
            }
        }
        if(ans.length() < indeg.size()) return "";
        return ans;
    }
};