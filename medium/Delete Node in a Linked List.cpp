/*
LC 237 - Delete Node in a Linked List
Time: O(1)
Space: O(1)

Logic: just follow the hint from the question
1. Copy next node value to current node
2. Remove next node by bypassing it
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};