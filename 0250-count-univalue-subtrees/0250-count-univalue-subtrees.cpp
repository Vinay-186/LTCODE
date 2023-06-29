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
    int count = 0;
    bool helper(TreeNode* root){
        if(root == NULL) return true;
        bool l= helper(root->left);
        bool r= helper(root->right);
        if(l && r){
            if(root->left && root->left->val != root->val) return false;
            if(root->right && root->right->val != root->val) return false;
            count++;
            return true;
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        helper(root);
        return count;
    }
};