class Node{
  public : 
    int x, y, z;
    Node(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class NodeComparator{
    public : 
    bool operator()(const Node& node1, const Node& node2) const{
        if(node1.z != node2.z)
            return node1.z > node2.z;
        if(node1.x != node2.x)
            return node1.x > node2.x;
        return node1.y > node2.y;
    }
};


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<Node, vector<Node>, NodeComparator> pq;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m , vector<int>(n, 1e9));
        dist[0][0]= 0;
        pq.push(Node(0,0,0));
        int dx[4] = {1,-1, 0, 0};
        int dy[4] = {0,0,-1,1};
        while(!pq.empty()){
            auto [x,y,z] = pq.top();
            pq.pop();
            if(x == m-1 && y == n-1) return z;
            for(int i = 0; i < 4; i++){
                int nrow = x + dx[i];
                int ncol = y + dy[i];
                if(nrow < 0 || ncol < 0 || nrow == m || ncol == n) continue;
                int cur_effort = max(z, abs(heights[x][y] - heights[nrow][ncol]));
                if(cur_effort < dist[nrow][ncol]){
                    dist[nrow][ncol] = cur_effort;
                    pq.push(Node(nrow, ncol, cur_effort));
                }
            }
        }
        return 0;
    }
};