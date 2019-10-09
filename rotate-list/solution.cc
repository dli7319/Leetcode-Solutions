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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* end = head;
        int len = 1;
        while (end->next != NULL) {
            end = end->next;
            len++;
        }
        end->next = head;
        int shifts = len - (k % len);
        for (int i = 0; i < shifts; i++) {
            end = end->next;
        }
        head = end->next;
        end->next = NULL;
        return head;
    }
};
