class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> st;
        vector<set<int>> adj(n+1);
        for(vector<int>& i : trust){
            adj[i[0]].insert(i[1]);
            st.insert(i.front());
        }
        int ans = -1;
        for(int i = 1; i <= n;i++){
            if(st.find(i) == st.end()){
                ans = i;
                break;
            }
        }
        if(ans == -1) return ans;
        for(int i = 1; i <= n; i++){
            if(i == ans) continue;
            if(adj[i].find(ans) == adj[i].end()) return -1;
        }
        return ans;
    }
};