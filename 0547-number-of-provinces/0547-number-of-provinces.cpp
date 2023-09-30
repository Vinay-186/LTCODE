class Solution {
public:
    vector<int> parent, rank;
    int count;
    int findPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void union_ds(int node1, int node2){
        int par1 = findPar(node1);
        int par2 = findPar(node2);
        if(par1 == par2) return;
        if(rank[par1] < rank[par2]) parent[par1]= par2;
        else if(rank[par2]< rank[par1]) parent[par2] = par1;
        else{
            parent[par1] = par2;
            rank[par2]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        count = n;
        rank.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(int i = 0; i <n;i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(isConnected[i][j] && findPar(i) != findPar(j)){
                    count--;
                    union_ds(i, j);
                }
            }
        }
        return count;
    }
};