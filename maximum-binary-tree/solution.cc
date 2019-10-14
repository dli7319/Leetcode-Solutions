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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        int max_idx = -1;
        int max_val = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max_val) {
                max_idx = i;
                max_val = nums[i];
            }
        }
        auto new_node = new TreeNode(max_val);
        if (max_idx > 0) {
            vector<int> sub(nums.begin(), nums.begin() + max_idx);
            new_node->left = constructMaximumBinaryTree(sub);
        }
        if (max_idx + 1 < nums.size()) {
            vector<int> sub(nums.begin() + max_idx + 1, nums.end());
            new_node->right = constructMaximumBinaryTree(sub);
        }
        return new_node;
    }
};
