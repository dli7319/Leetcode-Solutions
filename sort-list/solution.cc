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
//     Mergesort
    ListNode* merge(ListNode* a, ListNode* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        ListNode head(0);
        ListNode* last = &head;
        while (a != NULL && b != NULL) {
            if (a->val < b->val) {
                last->next = a;
                last = a;
                a = a->next;
            } else {
                last->next = b;
                last = b;
                b = b->next;
            }
        }
        if (a != NULL) {
            last->next = a;
            last = a;
        }
        if (b != NULL) {
            last->next = b;
            last = b;
        }
        ListNode *c = head.next;
        return head.next;
    }
    int getLen(ListNode* a) {
        int len = 0;
        while (a != NULL) {
            len++;
            a = a->next;
        }
        return len;
    }
    vector<ListNode *> split(ListNode* a) {
        int len = getLen(a);
        ListNode* prev = NULL;
        ListNode* b = a;
        for (int i = 0; i < len/2; i++) {
            prev = b;
            b = b->next;
        }
        if (prev != NULL)
            prev->next = NULL;
        return vector<ListNode *>{a, b};
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        vector<ListNode *> sides = split(head);
        ListNode* a = sortList(sides[0]);
        ListNode* b = sortList(sides[1]);
        return merge(a, b);
    }
};
