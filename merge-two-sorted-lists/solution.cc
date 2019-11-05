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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *nh = NULL;
        ListNode *nl = NULL;
        ListNode *l1a = l1;
        ListNode *l2a = l2;
        while(l1a != NULL || l2a != NULL) {
            if (l2a == NULL ||
                (l1a != NULL && l2a != NULL && l1a->val < l2a->val)) {
                if (nh == NULL) {
                    nl = nh = l1a;
                } else {
                    nl->next = l1a;
                    nl = nl->next;
                }
                l1a = l1a->next;
            } else {
                if (nl == NULL) {
                    nl = nh = l2a;
                } else {
                    nl->next = l2a;
                    nl = nl->next;
                }
                l2a = l2a->next;
            }
        }
        return nh;
    }
};
