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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        int pre = 0;
        return helper(preorder, inorder, pre, 0, inorder.size(), index);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int& pre_idx, int in_idx_l, int in_idx_r,
                     unordered_map<int, int>& index) {
        if (pre_idx >= preorder.size()) return NULL;
        int my_num = preorder[pre_idx++];
        int in_idx2 = index[my_num];
        if (in_idx2 >= in_idx_r) {
            pre_idx--;
            return NULL;
        }
        TreeNode *my_node = new TreeNode(my_num);
        if (in_idx_l + 1 == in_idx_r) return my_node;
        my_node->left = helper(preorder, inorder, pre_idx, in_idx_l, in_idx2, index);
        my_node->right = helper(preorder, inorder, pre_idx, in_idx2 + 1, in_idx_r, index);
        return my_node;
    }
};
