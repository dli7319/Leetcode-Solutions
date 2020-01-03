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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        unordered_set<TreeNode *> visited;
        stack<TreeNode *> my_stack;
        my_stack.push(root);
        while (!my_stack.empty()) {
            auto tip = my_stack.top();
            my_stack.pop();
            if (tip == NULL) {

            } else if (visited.find(tip) != visited.end()) {
                ans.push_back(tip->val);
            } else {
                visited.insert(tip);
                my_stack.push(tip->right);
                my_stack.push(tip);
                my_stack.push(tip->left);
            }
        }
        return ans;
    }
};
