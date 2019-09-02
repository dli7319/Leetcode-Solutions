/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> t;
        stack<Node *> nodes;
        set<Node *> processed;
        if (root == NULL) {
            return t;
        }
        nodes.push(root);
        while (!nodes.empty()) {
            Node *n = nodes.top();
            if (processed.find(n) != processed.end()) {
                nodes.pop();
                t.push_back(n->val);
            } else {
                for (int i = n->children.size() - 1; i >= 0; i--) {
                    nodes.push(n->children[i]);
                }
                processed.insert(n);
            }
        }
        return t;
    }
};
