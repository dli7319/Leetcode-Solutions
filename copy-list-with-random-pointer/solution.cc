/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node *,Node*> memo;
        Node *cur = head;
        Node *my_list = NULL;
        Node *my_list_head = NULL;
        while (cur != NULL) {
            Node *new_node = new Node(cur->val, NULL, cur->random);
            if (my_list == NULL) {
                my_list_head = my_list = new_node;
            } else {
                my_list->next = new_node;
                my_list = my_list->next;
            }
            memo[cur] = new_node;
            cur = cur->next;
        }
        my_list = my_list_head;
        while (my_list != NULL) {
            if (my_list->random != NULL) {
                my_list->random = memo[my_list->random];
            }
            my_list = my_list->next;
        }
        return my_list_head;
    }
};
