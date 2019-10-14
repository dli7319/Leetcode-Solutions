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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (val >= root->val) {
            auto temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
