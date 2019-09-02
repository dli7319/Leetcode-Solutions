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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *retHead = head;
        bool delB = retHead->val == retHead->next->val;
        int delI = retHead->val;
        while (delB && retHead != NULL) {
            retHead = retHead->next;
            delB = (retHead != NULL && retHead->val == delI);
            if (!delB && retHead != NULL && retHead->next != NULL) {
                delB = retHead->val == retHead->next->val;
                delI = retHead->val;
            }
        }
        if (retHead == NULL) {
            return NULL;
        }
        ListNode *prev = retHead;
        ListNode *cur = retHead->next;
        while (cur != NULL) {
            if (delB) {
                if (cur->val == delI) {
                    // cout << "Deleting " << delI << endl;
                    cur = cur->next;
                    prev->next = cur;
                } else {
                    delB = false;
                }
            } else if (cur->next != NULL && cur->val == cur->next->val) {
                delB = true;
                delI = cur->val;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return retHead;
    }
};
