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
    ListNode* head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* n = head;
        int ct = 1;
        int val = 0;
        while (n != NULL) {
            float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            if (r <= 1.0f / ct) {
                val = n->val;
            }
            n = n->next;
            ct++;
        }
        return val;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
