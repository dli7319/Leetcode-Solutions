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
private:
    int getMaxDepth(TreeNode* root, int depth) {
        if (root == NULL) {
            return depth;
        }
        return max(getMaxDepth(root->left, depth+1), getMaxDepth(root->right, depth+1));
    }
public:
    int maxDepth(TreeNode* root) {
        return getMaxDepth(root, 0);
    }
};
