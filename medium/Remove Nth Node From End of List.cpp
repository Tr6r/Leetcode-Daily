/*
LC 19 - Remove Nth Node From End of List.
Time : O(N) - 2 time traverse every node in link list.
Space : O(1)

Logic: apply counting Method
1. Traverse all nodes in the linked list to count the total number of nodes.
2. Find the index of the node that needs to be deleted from the beginning of the linked list.
3. Traverse the linked list again and delete the target node.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = NULL;
        ListNode* nhead = head;
        int node_del;
        int count = 0;

        if (head == NULL || head->next == NULL) {
            nhead = NULL;
            return nhead;
        }
        while (head) {
            count++;
            head = head->next;
        }
        node_del = count - n ;
        count = 0;
        head = nhead;
        pre = NULL;
        while (head) {
            if (node_del == count) {
                if (pre == NULL) 
                    nhead = head->next;
                else
                    pre->next = head->next;
                break;
            }
            count++;
            pre = head;
            head = head->next;
        }
        return nhead;
    }
};