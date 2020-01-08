/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int getLen(ListNode* head) {
        ListNode* t = head;
        int ct = 0;
        while (t != NULL) {
            ct++;
            t = t->next;
        }
        return ct;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        int len = getLen(head);
        ListNode* prev = NULL;
        ListNode* curr = head;
        for (int i = 0; i < len/2; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        TreeNode* my_node = new TreeNode(curr->val);
        my_node->left = sortedListToBST(head);
        my_node->right = sortedListToBST(curr->next);
        return my_node;
    }
};
