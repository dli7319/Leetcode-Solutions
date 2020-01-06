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
    TreeNode* join(TreeNode* l, TreeNode* r) {
        if (l == NULL) return r;
        TreeNode *t = l;
        while (t->right != NULL) {
            t = t->right;
        }
        t->right = r;
        return l;
    }
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *t = join(root->left, root->right);
        root->left = NULL;
        root->right = t;
    }
};
