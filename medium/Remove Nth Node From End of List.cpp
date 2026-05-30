/*
LC 19 - Remove Nth Node From End of List.
Time : O(N) - 1 time traverse every node in link list.
Space : O(1)

Logic: apply fast and slow Method
1. Move the fast pointer n times.
2. Move both fast and slow pointers until the fast pointer reaches NULL.
3. Replace the next node of the slow pointer with the next next node.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* fast = head;
        ListNode* slow = &dummy;
        int count = 0;
        if (!head->next) {
            return NULL;
        }
        while (fast) {
            if (count < n) {
                fast = fast->next;
            } else {
                slow = slow->next;
                fast = fast->next;
            }
            count++;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};