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
    bool hasLength(ListNode* head, int k) {
        for (int i = 0; i < k; i++) {
            if (head == NULL) return false;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (!hasLength(head, k)) return head;
        ListNode* prev = head;
        ListNode* second = head->next;
        for (int i = 1; i < k && second != NULL; i++) {
            ListNode* t = second->next;
            second->next = prev;
            prev = second;
            second = t;
        }
        // if (second != NULL) {
        //     cout << "Second val " << second->val << endl;
        // } else {
        //     cout << "Second is null" << endl;
        // }
        head->next = reverseKGroup(second, k);
        return prev;
    }
};
