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
    void helper(vector<vector<int>> &memo, TreeNode* root, int level) {
        if (root == NULL) return;
        for (int i = memo.size()-1; i < level; i++) {
            memo.push_back(vector<int>());
        }
        memo[level].push_back(root->val);
        helper(memo, root->left, level+1);
        helper(memo, root->right, level+1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> memo;
        helper(memo, root, 0);
        std::reverse(memo.begin(), memo.end());
        return memo;
    }
};
