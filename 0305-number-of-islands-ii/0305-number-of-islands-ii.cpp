class UnionFind{
    public: 
    vector<int> group;
    vector<int> rank;
    int count;
    UnionFind(int n){
        group = vector<int>(n, -1);
        rank = vector<int>(n, 0);
        count = 0;
    }
    
    void addLand(int node){
        if(group[node] >= 0) return;
        group[node] = node;
        count++;
    }
    
    bool isLand(int x){
        if(group[x] >= 0) return true;
        return false;
    }
    
    int answer() { return count; }
    
    int find(int node){
        if(group[node] != node){
            group[node] = find(group[node]);
        }
        return group[node];
    }
    
    void join(int node1, int node2){
        int group1 = find(node1);
        int group2 = find(node2);
        if(group1== group2) return ;
        if(rank[group1] > rank[group2]){
            group[group2] = group1;
        }else if(rank[group1] < rank[group2]){
            group[group1] = group2;
        }else{
            group[group1] = group2;
            rank[group2]++;
        }
        count--;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UnionFind uf(m*n);
        int x[4] = {-1, 1, 0,0};
        int y[4] = {0, 0, -1,1};
        vector<int> answer;
        for(auto& pos : positions){
            int landPosition = pos[0] * n + pos[1];
            uf.addLand(landPosition);
            for(int i = 0; i < 4; i++){
                int nx = pos[0] + x[i];
                int ny = pos[1] + y[i];
                int npos = nx  * n + ny;
                if(nx < 0 || ny < 0 || nx == m || ny == n) continue;
                if(uf.isLand(npos)) uf.join(landPosition, npos);
            }
            answer.push_back(uf.answer());
        }
        return answer;
    }
};