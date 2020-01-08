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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        unordered_set<TreeNode *> checked;
        stack<TreeNode *> to_check;
        to_check.push(root);
        while (!to_check.empty()) {
            TreeNode *curr = to_check.top();
            to_check.pop();
            if (curr != NULL) {
                if (checked.find(curr) == checked.end()) {
                    to_check.push(curr->right);
                    to_check.push(curr->left);
                    to_check.push(curr);
                    checked.insert(curr);
                } else {
                    ans.push_back(curr->val);
                }
            }
        }
        return ans;
    }
};
