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
    TreeNode* convertBST(TreeNode* root) {
        convBST(root, 0);
        return root;
    }

    int convBST(TreeNode* root, int t) {
        if (root == NULL) {
            return 0;
        }
        int a = convBST(root->right, t);
        int c = root->val;
        int b = convBST(root->left, t + a + c);
        root->val = root->val + t + a;
        // std::cout << "New val " << a << std::endl;
        return a + b + c;
    }
};
