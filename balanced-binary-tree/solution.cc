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
    int isBalancedHelper(TreeNode* root) {
        if (root == NULL) return 0;
        int l = isBalancedHelper(root->left);
        int r = isBalancedHelper(root->right);
        if (l < 0 || r < 0 || abs(l-r) > 1) return -1;
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root) >= 0;
    }
};
