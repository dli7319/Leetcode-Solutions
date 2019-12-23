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
    void levelOrderHelper(TreeNode* root, int level, vector<vector<int>> &traverse) {
        if (root == NULL) {
            return;
        }
        if (traverse.size() <= level) {
            traverse.push_back(vector<int>());
        }
        traverse[level].push_back(root->val);
        levelOrderHelper(root->left, level+1, traverse);
        levelOrderHelper(root->right, level+1, traverse);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traverse;
        levelOrderHelper(root, 0, traverse);
        return traverse;
    }
};
