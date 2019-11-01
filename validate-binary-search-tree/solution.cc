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
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }

    bool helper(TreeNode* root, int64_t min, int64_t max) {
        if (root == NULL) return true;
        if (root->val < min || root->val > max) {
            return false;
        }
        if (root->left != NULL && root->left->val >= root->val) {
            return false;
        }
        if (root->right != NULL && root->right->val <= root->val) {
            return false;
        }
        return helper(root->left, min, (int64_t)root->val-1) &&
            helper(root->right, (int64_t)root->val+1, max);
    }
};
