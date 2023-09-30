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
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i <n; i++) parent[i] = i;
        int cnt = 0;
        for(vector<int> connection : connections){
            if(findPar(connection[0]) != findPar(connection[1])){
                union_ds(connection[0], connection[1]);
            }else cnt++;
        }
        int sets = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i) sets++;
        }
        if(sets - 1 <= cnt) return sets-1;
        return -1;
    }
};