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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lower = NULL;
        ListNode *lowerE = NULL;
        ListNode *higher = NULL;
        ListNode *higherE = NULL;
        for (ListNode *c = head; c != NULL; c = c->next) {
            // cout << "val " << c->val << endl;
            if (c->val < x) {
                if (lower == NULL) {
                    lower = c;
                    lowerE = c;
                } else {
                    lowerE->next = c;
                    lowerE = c;
                }
            } else {
                if (higher == NULL) {
                    higher = c;
                    higherE = c;
                } else {
                    higherE->next = c;
                    higherE = c;
                }
            }
        }
        if (lower != NULL) {
            lowerE->next = higher;
        }
        if (higher != NULL) {
            higherE->next = NULL;
        }
        if (lower != NULL) {
            return lower;
        }
        return higher;
    }
};
