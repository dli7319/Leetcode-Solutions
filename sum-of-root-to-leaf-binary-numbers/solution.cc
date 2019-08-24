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
    int sumRootToLeaf(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        return sumRootToLeafHelper(root->left, root->val) +
            sumRootToLeafHelper(root->right, root->val);
    }

    int sumRootToLeafHelper(TreeNode* root, int currentSum) {
        if (root == NULL)
            return 0;
        int newSum = (currentSum << 1) | root->val;
        if (root->left == NULL && root->right == NULL)
            return newSum;
        return sumRootToLeafHelper(root->left, newSum) +
            sumRootToLeafHelper(root->right, newSum);
    }
};
