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
    TreeNode* sharedArrayToBST(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return NULL;
        } else if (start+1 == end) {
            return new TreeNode(nums[start]);
        } else {
            int middle = (start + end) / 2;
            auto node = new TreeNode(nums[middle]);
            node->left = sharedArrayToBST(nums, start, middle);
            node->right = sharedArrayToBST(nums, middle + 1, end);
            return node;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sharedArrayToBST(nums, 0, nums.size());
    }
};
