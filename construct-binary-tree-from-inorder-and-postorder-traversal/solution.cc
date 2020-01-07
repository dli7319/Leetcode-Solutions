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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_hash;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_hash[inorder[i]] = i;
        }
        int post_idx = postorder.size() - 1;
        return helper(inorder, postorder, post_idx, 0, inorder.size(), inorder_hash);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,
                     int& post_idx, int in_idx_l, int in_idx_r,
                    unordered_map<int, int>& inorder_hash) {
        if (post_idx < 0) return NULL;
        int my_val = postorder[post_idx];
        int in_idx = inorder_hash[my_val];
        if (in_idx < in_idx_l || in_idx >= in_idx_r) {
            return NULL;
        }
        post_idx--;
        TreeNode *my_node = new TreeNode(my_val);
        if (in_idx_l + 1 == in_idx_r) return my_node;
        my_node->right =
            helper(inorder, postorder, post_idx, in_idx + 1, in_idx_r, inorder_hash);
        my_node->left =
            helper(inorder, postorder, post_idx, in_idx_l, in_idx, inorder_hash);
        return my_node;
    }
};
