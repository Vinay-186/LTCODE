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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>> qp;
        qp.push({p,q});
        while(!qp.empty()){
            TreeNode* node1 = qp.front().first;
            TreeNode* node2 = qp.front().second;
            qp.pop();
            if(node1 == NULL && node2 == NULL) return true;
            if(node1 != NULL && node2 == NULL || node1 == NULL && node2 != NULL) return false;
            if(node1->val != node2->val) return false;
            if(node1->left != NULL || node2->left != NULL) qp.push({node1->left, node2->left});
            if(node1->right != NULL || node2->right != NULL) qp.push({node1->right,node2->right});
        }
        return true;
    }
};