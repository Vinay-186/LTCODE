/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* root = new Node(node->val);
        map<Node*, Node*> vis;
        vis[node] = root;
        queue<pair<Node*, Node*>> q;
        q.push({node, root});
        while(!q.empty()){
            auto [n, c] = q.front();
            q.pop();
            for(Node* i : n->neighbors){
                if(vis.find(i) == vis.end()){
                    Node* temp = new Node(i->val);
                    vis[i] = temp;
                    c->neighbors.push_back(temp);
                    q.push({i, temp});
                }else{
                    c->neighbors.push_back(vis[i]);
                }
            }
        }
        return root;
    }
};