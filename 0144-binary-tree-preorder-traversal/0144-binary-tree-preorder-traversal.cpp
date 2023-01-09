/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> p;
        if(root == NULL) return p;
        stack<TreeNode*> b;
        b.push(root);
        while(!b.empty()){
            TreeNode* node = b.top();
            b.pop();
            p.push_back(node->val);
            if(node->right) b.push(node->right);
            if(node->left) b.push(node->left);
        }
        return p;
    }
};