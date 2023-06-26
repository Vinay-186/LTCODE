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
    void inorder(TreeNode* root, vector<int>& io){
        if(root == NULL) return;
        inorder(root->left, io);
        io.push_back(root->val);
        inorder(root->right,io);
    }
int binarySearch(vector<int>& arr, int l, int r, int target)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target)
            return m;
        if (arr[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> io1, io2;
        inorder(root1, io1);
        inorder(root2, io2);
        for(int i : io1){
            if(binarySearch(io2, 0, io2.size()-1,target - i) != -1) return true;
        }
        return false;
    }
};