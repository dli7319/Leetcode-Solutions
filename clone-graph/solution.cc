/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> temp;
        return helper(node, temp);
    }

    Node *helper(Node* node, unordered_map<Node*, Node*> &memo) {
        if (node == NULL) return NULL;
        Node *existing = memo[node];
        if (existing != NULL) return existing;
        Node *my_node = new Node(node->val, vector<Node*>(node->neighbors.size()));
        memo[node] = my_node;
        for (int i = 0; i < node->neighbors.size(); i++) {
            my_node->neighbors[i] = helper(node->neighbors[i], memo);
        }
        return my_node;
    }
};
