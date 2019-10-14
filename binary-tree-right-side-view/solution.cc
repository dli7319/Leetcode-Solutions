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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> hi;
        helper(root, 0, hi);
        return hi;
    }

    void helper(TreeNode* root, int depth, vector<int> &hi) {
        if (root == NULL) {
            return;
        }
        if (depth == hi.size()) {
            hi.push_back(0);
        }
        hi[depth] = root->val;
        helper(root->left, depth+1, hi);
        helper(root->right, depth+1, hi);
    }
};
