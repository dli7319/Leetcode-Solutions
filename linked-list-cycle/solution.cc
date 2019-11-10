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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *r1 = head;
        ListNode *r2 = head;
        while (true) {
            if (r1 == NULL) return false;
            r1 = r1->next;
            if (r2 == NULL || r2->next == NULL) return false;
            r2 = r2->next;
            r2 = r2->next;
            if (r1 == r2) return true;
        }
    }
};
