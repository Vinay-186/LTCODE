/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, map<TreeNode*, TreeNode*>& parent){
        if(root== NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right)parent[root->right] = root;
        preorder(root->left, parent);
        preorder(root->right, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        map<TreeNode*, int> vis;
        queue<TreeNode*> q;
        parent[root] = NULL;
        preorder(root, parent);
        int dis = 0;
        q.push(target);
        vis[target] = 1;
        vector<int> res;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto node = q.front();
                q.pop();
                if(dis == k) res.push_back(node->val);
                if(parent[node] && vis.find(parent[node]) == vis.end()){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
                if(node->left && vis.find(node->left) == vis.end()){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && vis.find(node->right) == vis.end()){
                    q.push(node->right);
                    vis[node->right]=1;
                }
            }
            dis++;
        }
        return res;
    }
};