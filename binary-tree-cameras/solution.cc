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
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode *> needsCamera;
        unordered_set<TreeNode *> processed;
        stack<TreeNode *> nodesToProcess;
        nodesToProcess.push(root);

        int camerasCount = 0;
        while(!nodesToProcess.empty()) {
            TreeNode *node = nodesToProcess.top();
            if (processed.find(node) == processed.end()) {
                processed.insert(node);
                if (node->left != NULL) {
                    nodesToProcess.push(node->left);
                }
                if (node->right != NULL) {
                    nodesToProcess.push(node->right);
                }
            } else {
                bool thisNeedsCamera = false;
                nodesToProcess.pop();
                camerasCount++;
                if ((node->left != NULL) &&
                    (needsCamera.find(node->left) == needsCamera.end())) {
                    // Remove camera from left node.
                    camerasCount--;
                    if (!connectedToCamera(node->left, needsCamera))
                        thisNeedsCamera = true;
                }
                if ((node->right != NULL) &&
                    (needsCamera.find(node->right) == needsCamera.end())) {
                    // Remove camera from right node.
                    camerasCount--;
                    if (!connectedToCamera(node->right, needsCamera))
                        thisNeedsCamera = true;
                }
                if (nodesToProcess.empty() && !connectedToCamera(node, needsCamera)) {
                    thisNeedsCamera = true;
                }
                if (thisNeedsCamera) {
                    needsCamera.insert(node);
                }
                if (nodesToProcess.empty() && !thisNeedsCamera &&
                    (node->left != NULL || node->right != NULL)) {
                    camerasCount--;
                }
            }
        }
        return camerasCount;
    }

    bool connectedToCamera(TreeNode *node, unordered_set<TreeNode *> needsCamera) {
        if (node->left != NULL && needsCamera.find(node->left) != needsCamera.end()) {
            return true;
        }
        if (node->right != NULL && needsCamera.find(node->right) != needsCamera.end()) {
            return true;
        }
        return false;
    }
};
