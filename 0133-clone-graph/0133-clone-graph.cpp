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
    void dfs(Node* node, Node* clone, map<Node*, Node*>& vis){
        vis[node] = clone;
        for(Node* i : node->neighbors){
            if(vis.find(i) == vis.end()){
                Node* temp = new Node(i->val);
                clone->neighbors.push_back(temp);
                dfs(i, temp, vis);
            }
            else {
                clone->neighbors.push_back(vis[i]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* root = new Node(node->val);
        map<Node*, Node*> vis;
        vis[node] = root;
        dfs(node, root, vis);
        return root;
    }
};