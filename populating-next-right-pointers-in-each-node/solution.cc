/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        vector<Node *> hi;
        helper(root, 0, hi);
        return root;
    }

    void helper(Node* root, int depth, vector<Node *> &hi) {
        if (root == NULL) {
            return;
        }
        if (depth == hi.size()) {
            hi.push_back(NULL);
        }
        root->next = hi[depth];
        hi[depth] = root;
        helper(root->right, depth + 1, hi);
        helper(root->left, depth + 1, hi);
        return;
    }
};
