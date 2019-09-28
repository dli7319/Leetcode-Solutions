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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        ListNode *first = NULL;
        ListNode *last = NULL;
        bool allNull = false;
        while(!allNull) {
            allNull = true;
            ListNode *smallest = NULL;
            int smallestIdx = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL) {
                    if (smallest == NULL || lists[i]->val < smallest->val) {
                        smallest = lists[i];
                        smallestIdx = i;
                        allNull = false;
                    }
                }
            }
            if (!allNull && first == NULL) {
                first = smallest;
                last = smallest;
                lists[smallestIdx] = smallest->next;
            } else if (!allNull) {
                last->next = smallest;
                last = last->next;
                lists[smallestIdx] = smallest->next;
            }
        }
        return first;
    }
};
