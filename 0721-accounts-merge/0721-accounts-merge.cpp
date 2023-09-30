class Solution {
public:
    vector<int> parent, rank;
    int findPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void union_ds(int node1, int node2){
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if(par1 == par2) return;
        if(rank[par1] > rank[par2]) parent[par2] = par1;
        else if(rank[par2] > rank[par1]) parent[par1] = par2;
        else{
            parent[par1] = par2;
            rank[par2]++;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string, int> mp;
        for(int i =0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }else{
                    union_ds(i, mp[mail]);
                }
            }
        }
        
        vector<vector<string>> ans(n);
        for(auto i : mp){
            string mail = i.first;
            int node = findPar(i.second);
            ans[node].push_back(mail);
        }
        
        vector<vector<string>> res;
        for(int i = 0; i < n; i++){
            if(!ans[i].empty()){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(ans[i].begin(), ans[i].end());
                temp.insert(temp.end(), ans[i].begin(), ans[i].end());
                res.push_back(temp);
            }
        }
        return res;
        
    }
};