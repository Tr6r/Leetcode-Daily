/*
LC 203 - Remove Linked List Elements.
Time : O(N) - traverse every node in the head list once.
Space : O(N) - create a new node in each iteration in the worst case.

Logic:
1. Create a new linked list with a head and tail pointer.
2. traverse every node in the original list. 
3. If the current node's value is unequal to the given value:
   - Create a new node with that value.
   - Append it to the new list.
4. Move the tail pointer to the newly added node.
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *new_head = NULL;
        ListNode *tail = NULL;
        if (!head) return new_head;
        while ( head != NULL)
        {
            if (head->val != val)
            {
                ListNode *new_node = new ListNode;
                new_node->val = head->val;
                if(new_head == NULL)
                {
                    new_head = tail = new_node;
                    head = head->next;
                    continue;
                }
                tail->next = new_node;
                tail = new_node;
            }
            head = head->next;
        }
        return new_head;
    }
};