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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        int count = 0;
        ListNode *firstHalf = head;
        while (firstHalf != NULL) {
            count++;
            firstHalf = firstHalf->next;
        }
        ListNode *prev = NULL;
        ListNode *next = NULL;
        firstHalf = head;
        ListNode *secondHalf = NULL;
        // Reverse the first half of the list.
        // You can reverse it back later if you keep a reference to the middle.
        for (int i = 0; i < count / 2 - 1; i++) {
            next = firstHalf->next;
            firstHalf->next = prev;
            prev = firstHalf;
            firstHalf = next;
        }
        secondHalf = firstHalf->next;
        firstHalf->next = prev;
        if (count % 2 == 1) {
            secondHalf = secondHalf->next;
        }
        for (int i = 0; i < count / 2; i++) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};
