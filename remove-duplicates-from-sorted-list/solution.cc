/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        if (head->val == head->next->val) {
            head->next = head->next->next;
            return deleteDuplicates(head);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
