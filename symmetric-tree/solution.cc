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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode *>left;
        stack<TreeNode *>right;
        left.push(root);
        right.push(root);
        while (!left.empty() && !right.empty()) {
            TreeNode *l = left.top();
            TreeNode *r = right.top();
            left.pop();
            right.pop();
            if (l!=NULL && r!=NULL && l->val != r->val) {
                return false;
            }
            if ((l==NULL || r == NULL) && l!=r) {
                return false;
            }
            if (l!=root && l != NULL && l == r) {
                return true;
            }
            if (l!=NULL && r!=NULL) {
                left.push(l->right);
                left.push(l->left);
                right.push(r->left);
                right.push(r->right);
            }
        }
        return left.empty() && right.empty();
    }
};
