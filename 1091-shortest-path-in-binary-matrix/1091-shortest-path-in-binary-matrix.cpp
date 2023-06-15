class Node{
public :
    int x, y, z;
    Node(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    bool operator ==(const Node& n)const{
        return (this->x == n.x && this->y == n.y);
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[8] = {1,1,-1,-1,1,-1,0,0};
        int dy[8] = {1,-1,1,-1,0,0,1,-1};
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        Node n1(0,0,1);
        Node n2(n-1,n-1,0);
        queue<Node> q;
        q.push(n1);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node == n2) return node.z;
            for(int i = 0; i < 8; i++){
                int nrow = node.x + dx[i];
                int ncol = node.y + dy[i];
                if(nrow < 0 || ncol < 0 || nrow == n || ncol == n || 
                   grid[nrow][ncol] == 1) continue;
                q.push(Node(nrow, ncol, node.z +1));
                grid[nrow][ncol] = 1;
            }
        }
        return -1;
    }
};