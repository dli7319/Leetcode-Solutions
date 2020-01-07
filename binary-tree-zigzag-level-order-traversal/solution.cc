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
    void levelTraverse(TreeNode* root, int level, vector<vector<int>>& trav) {
        if (root == NULL) return;
        if (level + 1 > trav.size()) trav.resize(level + 1);
        trav[level].push_back(root->val);
        levelTraverse(root->left, level+1, trav);
        levelTraverse(root->right, level+1, trav);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> trav;
        levelTraverse(root, 0, trav);
        for (int i = 1; i < trav.size(); i += 2) {
            std::reverse(trav[i].begin(), trav[i].end());
        }
        return trav;
    }
};
