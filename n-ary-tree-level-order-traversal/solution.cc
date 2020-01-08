/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void helper(Node* root, int level, vector<vector<int>>& ans) {
        if (root == NULL) return;
        if (level + 1> ans.size()) {
            ans.resize(level+1);
        }
        ans[level].push_back(root->val);
        for (Node *n : root->children) {
            helper(n, level+1, ans);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        helper(root, 0, ans);
        return ans;
    }
};
