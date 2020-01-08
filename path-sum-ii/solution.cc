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
    void helper(TreeNode* root, int sum,
                vector<int>& curr,
                vector<vector<int>>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                curr.push_back(root->val);
                ans.push_back(curr);
                curr.pop_back();
            }
            return;
        }
        curr.push_back(root->val);
        helper(root->left, sum - root->val, curr, ans);
        helper(root->right, sum - root->val, curr, ans);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(root, sum, curr, ans);
        return ans;
    }
};
