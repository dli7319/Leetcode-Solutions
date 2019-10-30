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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode* a = head;
        ListNode* b = head;
        int traversed = 0;
        for (int i = 0; i <= n && b != NULL; i++) {
            b = b->next;
            traversed++;
        }
        while (b != NULL) {
            a = a->next;
            b = b->next;
        }
        if (traversed < n + 1) {
            return a->next;
        } else if (a->next != NULL) {
            a->next = a->next->next;
            return head;
        }
        return NULL;
    }
};
