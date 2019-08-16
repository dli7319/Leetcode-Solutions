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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flippedValues;
        stack<TreeNode *> nodeStack;
        int voyageSize = voyage.size();
        nodeStack.push(root);
        for (int i = 0; i < voyageSize; i++) {
            TreeNode *current = nodeStack.top();
            nodeStack.pop();
            bool done = false;
            if (voyage[i] != current->val) {
                return vector<int>{-1};
            }
            if (i+1 < voyageSize) {
                if (current->left != NULL || current->right != NULL) {
                    int nextNum = voyage[i+1];
                    if (current->left != NULL && current->left->val == nextNum) {
                        if (current->right != NULL)
                            nodeStack.push(current->right);
                        nodeStack.push(current->left);
                        done = true;
                    } else if ( current->left == NULL &&
                               current->right != NULL &&
                               current->right->val == nextNum) {
                        nodeStack.push(current->right);
                        done = true;
                    } else if (current->right != NULL &&
                               current->right->val == nextNum) {
                        nodeStack.push(current->left);
                        nodeStack.push(current->right);
                        flippedValues.push_back(current->val);
                        done = true;
                    }
                } else if (!nodeStack.empty()) {
                    done = true;
                }
            } else if (nodeStack.empty()) {
                done = true;
            }
            if (!done) {
                return vector<int>{-1};
            }
        }
        return flippedValues;
    }
};
