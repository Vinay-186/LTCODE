//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Node {
public:
    int x, y, weight;

    Node(pair<int,int> p, int weight) {
        this->x = p.first;
        this->y = p.second;
        this->weight = weight;
    }
};

class NodeComparator {
public:
    bool operator()(const Node& node1, const Node& node2) const {
        if (node1.weight != node2.weight)
            return node1.weight > node2.weight;  // Check weight first (min heap)
        if (node1.x != node2.x)
            return node1.x > node2.x;  // Check x next
        return node1.y > node2.y;     // Check y last
    }
};

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        int x = destination.first, y = destination.second;
        if(grid[x][y] == 0) return -1;
        priority_queue<Node, vector<Node> ,NodeComparator> pq;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        pq.push(Node(destination, 0));
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[x][y] = 0;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int x = node.x, y = node.y, dis = node.weight;
            for(int i = 0; i < 4; i++){
                int nrow = x + dx[i];
                int ncol = y + dy[i];
                if(nrow < 0 || ncol < 0 || nrow == m || ncol == n || 
                grid[nrow][ncol] == 0) continue;
                if(dis + 1 < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis + 1;
                    pq.push(Node({nrow, ncol}, dis+1));
                }
            }
        }
        if(dist[source.first][source.second] == 1e9) return -1;
        return dist[source.first][source.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends